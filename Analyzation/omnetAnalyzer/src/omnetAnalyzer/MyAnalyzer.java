package omnetAnalyzer;

import java.io.BufferedReader;
import java.util.ArrayList;
import java.util.stream.Collectors;

import cern.colt.list.DoubleArrayList;
import cern.jet.stat.Descriptive;

public abstract class MyAnalyzer {
	protected ArrayList<Integer> sentPackages = new ArrayList<>();
	protected ArrayList<Integer> receivedPackages = new ArrayList<>();

	public MyAnalyzer() {
		// 65 is nr of hosts in simulation
		// TODO extract var
		for (int i = 0; i < OmnetAnalyzer.NR_OF_HOSTS; i++) {
			this.sentPackages.add(0);
			this.receivedPackages.add(0);
		}
	}
	
	protected abstract String getAnalyzerName();

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

		this.parseIndividualLine(line, br);
	}

	/**
	 * Stuff every analyzer wants to do on his own
	 */
	protected abstract void parseIndividualLine(String line, BufferedReader br);
	
	public void getResult() throws Exception {
		System.out.println(this.getAnalyzerName());
		
		this.getIndividualResult();
	}

	protected abstract void getIndividualResult() throws Exception;

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
	
	protected void printStatistics(DoubleArrayList values) {
		double mean = Descriptive.mean(values);
		double variance = Descriptive.sampleVariance(values, mean);
		double standardDeviation = Descriptive.standardDeviation(variance);

		System.out.println("Mean: " + mean + "\nVar: " + variance
				+ "\nStddev: " + standardDeviation);
	}

	/**
	 * Get nr. of receivingHosts (package count > 0)
	 */
	protected int getNrOfReceivingHosts() {
		return this.receivedPackages.stream().filter(val -> val > 0)
				.collect(Collectors.toList()).size();
	}

	protected Integer extractInteger(String line) {
		return Integer.valueOf(line.substring(line.lastIndexOf(' ')).trim());
	}

	protected Double extractDouble(String line) {
		return Double.valueOf(line.substring(line.lastIndexOf(' ')).trim());
	}
}
