package omnetAnalyzer.analyzer;

import java.io.BufferedReader;

import omnetAnalyzer.MyAnalyzer;
import cern.colt.list.DoubleArrayList;

public class PacketLossAnalyzer extends MyAnalyzer {
	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
	}

	protected void getIndividualResult() throws Exception {
		DoubleArrayList packetLoss = new DoubleArrayList();

		for (int i = 0; i < this.sentPackages.size(); i++) {
			if (this.sentPackages.get(i) == 0) {
				packetLoss.add(100);
			} else {
				packetLoss
						.add(100 * (this.receivedPackages.get(i) / this.sentPackages
								.get(i)));
			}
		}

		// Calculating standard deviation doesn't make sense, because it is a
		// calculation of overall received / sent packages.
		double mean = 100 - 100 * this.getSumOfReceivedPackages()
				/ this.getSumOfSentPackages();

		System.out.println("Mean: " + mean);

		/*
		 * double mean = Descriptive.mean(packetLoss); double variance =
		 * Descriptive.sampleVariance(packetLoss, mean); double
		 * standardDeviation = Descriptive.standardDeviation(variance);
		 */
	}

	@Override
	protected String getAnalyzerName() {
		return "Packet Loss...";
	}
}
