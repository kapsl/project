package omnetAnalyzer.analyzer;

import java.io.BufferedReader;

import omnetAnalyzer.MyAnalyzer;
import omnetAnalyzer.OmnetAnalyzer;

/**
 * 
 * Calculate Packet Loss in percent
 * 
 * @author manuel
 *
 */
public class PacketLossAnalyzer extends MyAnalyzer {
	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
	}

	protected void getIndividualResult() throws Exception {
		// Calculating standard deviation doesn't make sense, because it is a
		// calculation of overall received / sent packages.
		double mean = 100 - 100.0 * this.getSumOfReceivedPackages()
				/ this.getSumOfSentPackages();

		String smean = String.format("%.2f", mean);

		OmnetAnalyzer.OUTPUT.add("Mean: " + smean);
		EXCEL_OUTPUT.add(smean + "\t" + "/");
	}

	@Override
	protected String getAnalyzerName() {
		return "Packet Loss...";
	}
}
