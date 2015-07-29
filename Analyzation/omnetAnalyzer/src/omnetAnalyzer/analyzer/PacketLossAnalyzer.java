package omnetAnalyzer.analyzer;

import java.io.BufferedReader;

import omnetAnalyzer.MyAnalyzer;

public class PacketLossAnalyzer extends MyAnalyzer {
	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
	}

	protected void getIndividualResult() throws Exception {
		// Calculating standard deviation doesn't make sense, because it is a
		// calculation of overall received / sent packages.
		double mean = 100 - 100 * this.getSumOfReceivedPackages()
				/ this.getSumOfSentPackages();

		System.out.println("Mean: " + mean);
	}

	@Override
	protected String getAnalyzerName() {
		return "Packet Loss...";
	}
}
