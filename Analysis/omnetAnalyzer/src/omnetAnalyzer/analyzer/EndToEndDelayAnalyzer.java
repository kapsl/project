package omnetAnalyzer.analyzer;

import java.io.BufferedReader;
import java.io.IOException;
import java.util.ArrayList;

import omnetAnalyzer.MyAnalyzer;
import cern.colt.list.DoubleArrayList;

/**
 * 
 * Get End to End Delay of the simulation in seconds
 * 
 * @author manuel
 *
 */
public class EndToEndDelayAnalyzer extends MyAnalyzer {
	/**
	 * The mean end to end delay per host
	 */
	private ArrayList<Double> meanEndToEndDelay = new ArrayList<>();

	/**
	 * The stddev of end to end delay per host
	 */
	private ArrayList<Double> stddevEndToEndDelay = new ArrayList<>();

	public EndToEndDelayAnalyzer() {
		super();

		this.initializeArrayForHosts(this.meanEndToEndDelay, 0.0);
		this.initializeArrayForHosts(this.stddevEndToEndDelay, null);
	}

	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
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
		ArrayList<Double> weightedMeanDelay = new ArrayList<>();

		// We have to weight the mean by the package count
		for (int i = 0; i < this.meanEndToEndDelay.size(); i++) {
			weightedMeanDelay.add(this.receivedPackages.get(i)
					* this.meanEndToEndDelay.get(i));
		}

		DoubleArrayList meanDelay = new DoubleArrayList();

		for (int i = 0; i < this.meanEndToEndDelay.size(); i++) {
			if (this.meanEndToEndDelay.get(i) != 0.0) {
				// Add this value nr. of received packages for this host times,
				// to get weighted mean
				for (int x = 0; x < this.receivedPackages.get(i); x++) {
					meanDelay.add(this.meanEndToEndDelay.get(i));
				}
			}
		}

		this.printStatistics(meanDelay);
	}

	@Override
	public void reset() {
		super.reset();

		this.initializeArrayForHosts(this.meanEndToEndDelay, 0.0);
		this.initializeArrayForHosts(this.stddevEndToEndDelay, null);
	}

	@Override
	protected String getAnalyzerName() {
		return "End to End Delay...";
	}
}
