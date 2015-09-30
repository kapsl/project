package omnetAnalyzer;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.stream.Collectors;

import omnetAnalyzer.analyzer.EndToEndDelayAnalyzer;
import omnetAnalyzer.analyzer.ThroughputAnalyzer;
import cern.colt.list.DoubleArrayList;
import cern.jet.stat.Descriptive;

/**
 * Abstract class for all Analyzers
 * 
 * @author manuel
 *
 */
public abstract class MyAnalyzer {
	public ArrayList<String> EXCEL_OUTPUT = new ArrayList<>();

	/**
	 * Sent and received udp packages (= the payload packages)
	 */
	protected ArrayList<Integer> sentPackages = new ArrayList<>();
	protected ArrayList<Integer> receivedPackages = new ArrayList<>();

	public MyAnalyzer() {
		this.initializeArrayForHosts(this.sentPackages, 0);
		this.initializeArrayForHosts(this.receivedPackages, 0);
	}

	/**
	 * Initialize a "bucket" for every host
	 */
	protected <T> void initializeArrayForHosts(ArrayList<T> list,
			T initializationValue) {
		list.clear();

		for (int i = 0; i < OmnetAnalyzer.NR_OF_HOSTS; i++) {

			list.add(initializationValue);
		}
	}

	protected abstract String getAnalyzerName();

	/**
	 * Reset all values, so that we can perform a new analysis
	 */
	public void reset() {
		this.initializeArrayForHosts(this.sentPackages, 0);
		this.initializeArrayForHosts(this.receivedPackages, 0);
	}

	/**
	 * Do parsing, that every analyzer needs
	 * 
	 * @param line
	 * @param br
	 */
	public void parseLine(String line, BufferedReader br) {
		// Sent packages
		if (line.contains("scalar") && line.contains("udp")
				&& line.contains("sentPk:count")) {
			this.sentPackages.set(this.extractHostNumber(line),
					this.extractInteger(line));
		}

		// Received packages
		else if (line.contains("scalar") && line.contains("udp")
				&& line.contains("rcvdPk:count")) {
			this.receivedPackages.set(this.extractHostNumber(line),
					this.extractInteger(line));
		}

		// Let every analyzer do his specific stuff
		this.parseIndividualLine(line, br);
	}

	/**
	 * Stuff every analyzer wants to do on his own
	 */
	protected abstract void parseIndividualLine(String line, BufferedReader br);

	/**
	 * Get result from analysis
	 * 
	 * @throws Exception
	 */
	public void getResult() throws Exception {
		OmnetAnalyzer.OUTPUT.add(this.getAnalyzerName());

		this.getIndividualResult();
	}

	/**
	 * Get analyzer specific result
	 * 
	 * @throws Exception
	 */
	protected abstract void getIndividualResult() throws Exception;

	/**
	 * Extract the host number from the line in the .sca file written like
	 * ...host[53]...
	 * 
	 * @param line
	 * @return
	 */
	protected Integer extractHostNumber(String line) {
		int hostVal = Integer.valueOf(line.substring(
				line.lastIndexOf("host[") + 5, line.lastIndexOf("].")));

		return hostVal;
	}

	/**
	 * Get sum of received packages
	 */
	protected int getSumOfReceivedPackages() {
		return this.receivedPackages.stream().mapToInt(value -> value).sum();
	}

	/**
	 * Get sum of sent packages
	 */
	protected int getSumOfSentPackages() {
		return this.sentPackages.stream().mapToInt(value -> value).sum();
	}

	/**
	 * Get mean, variance, standard deviation
	 * 
	 * @param values
	 *            in DoubleArrayList from cern colt library
	 */
	protected void printStatistics(DoubleArrayList values) {
		double mean = Descriptive.mean(values);
		double variance = Descriptive.sampleVariance(values, mean);
		double standardDeviation = Descriptive.standardDeviation(variance);

		OmnetAnalyzer.OUTPUT.add("Mean: " + mean + "\nVar: " + variance
				+ "\nStddev: " + standardDeviation);

		String sMean, sSdev;

		if (!(this instanceof EndToEndDelayAnalyzer)
				&& !(this instanceof ThroughputAnalyzer)) {
			sMean = String.format("%.2f", mean);
			sSdev = String.format("%.2f", standardDeviation);
		} else {
			sMean = String.format("%.5f", mean);
			sSdev = String.format("%.5f", standardDeviation);
		}

		EXCEL_OUTPUT.add(sMean + "\t" + sSdev);
	}

	/**
	 * Get nr. of receivingHosts (package count > 0)
	 */
	protected int getNrOfReceivingHosts() {
		return this.receivedPackages.stream().filter(val -> val > 0)
				.collect(Collectors.toList()).size();
	}

	/**
	 * Extract a integer value from the .sca file of a line
	 */
	protected Integer extractInteger(String line) {
		return Integer.valueOf(line.substring(line.lastIndexOf(' ')).trim());
	}

	/**
	 * Extract a double value from the .sca file of a line
	 */
	protected Double extractDouble(String line) {
		Double ret;

		try {
			ret = Double.valueOf(line.substring(line.lastIndexOf(' ')).trim());
		} catch (NumberFormatException e) {
			ret = 0.0;
		}

		return ret;
	}
}
