package omnetAnalyzer.analyzer;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;

import omnetAnalyzer.MyAnalyzer;
import omnetAnalyzer.OmnetAnalyzer;
import cern.colt.list.DoubleArrayList;

public class EndToEndDelayAnalyzer extends MyAnalyzer {
	/**
	 * The mean end to end delay per host
	 */
	private ArrayList<Double> meanEndToEndDelay = new ArrayList<>();

	/**
	 * The stddev of end to end delay per host
	 */
	private ArrayList<Double> stddevEndToEndDelay = new ArrayList<>();

	// TODO somehow externalize initialization
	public EndToEndDelayAnalyzer() {
		super();
		
		// 65 is nr of hosts in simulation
		for (int i = 0; i < OmnetAnalyzer.NR_OF_HOSTS; i++) {
			meanEndToEndDelay.add(0.0);
			stddevEndToEndDelay.add(null);
		}
	}

	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
		// End to end delay
		if (line.contains("statistic") && line.contains("udpApp")
				&& line.contains("endToEndDelay:histogram")) {
			int hostNumber = this.extractHostNumber(line);

			// Read the next lines
			try {
				// Count of packages - don't need it
				br.readLine();

				// Mean End to end delay
				double meanDelay = this.extractDouble(br.readLine());

				// Stddev end to end delay
				double stdvDelay = this.extractDouble(br.readLine());

				this.meanEndToEndDelay.set(hostNumber, meanDelay);
				this.stddevEndToEndDelay.set(hostNumber, stdvDelay);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	protected void getIndividualResult() throws Exception {
		double sumOfDelays = this.meanEndToEndDelay.stream()
				.mapToDouble(value -> value).sum();

		ArrayList<Double> weightedMeanDelay = new ArrayList<>();

		// TODO probably we have to weight the means by package count???? Ask Prof. Hähner
		for (int i = 0; i < this.meanEndToEndDelay.size(); i++) {
			weightedMeanDelay.add(this.receivedPackages.get(i) * this.meanEndToEndDelay.get(i));
		}

		double unweightedMean = sumOfDelays / this.getNrOfReceivingHosts();
		System.out.println("Unweighted Mean: " + unweightedMean);

		double sumOfWeightedMeans = weightedMeanDelay.stream()
				.mapToDouble(value -> value).sum();
		double weightedMean = sumOfWeightedMeans / this.getSumOfReceivedPackages();
		System.out.println("Weighted Mean: " + weightedMean);
		
		
		// Individual count TODO
		DoubleArrayList meanDelay = new DoubleArrayList();
		
		for (int i = 0; i < this.meanEndToEndDelay.size(); i++) {
			if (this.meanEndToEndDelay.get(i) != 0.0)
				meanDelay.add(this.meanEndToEndDelay.get(i));
		}
		
		this.printStatistics(meanDelay);
	}

	@Override
	protected String getAnalyzerName() {
		return "End to End Delay...";
	}
}
