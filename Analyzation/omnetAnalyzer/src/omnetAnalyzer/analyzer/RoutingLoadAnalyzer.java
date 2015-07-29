package omnetAnalyzer.analyzer;

import java.io.BufferedReader;
import java.util.ArrayList;

import omnetAnalyzer.MyAnalyzer;
import omnetAnalyzer.OmnetAnalyzer;
import cern.colt.list.DoubleArrayList;
import cern.jet.stat.Descriptive;

public class RoutingLoadAnalyzer extends MyAnalyzer {
	private ArrayList<Integer> routingPackages = new ArrayList<Integer>();

	public RoutingLoadAnalyzer() {
		super();
		
		// TODO 65 is nr of hosts in simulation
		for (int i = 0; i < OmnetAnalyzer.NR_OF_HOSTS; i++) {
			routingPackages.add(0);
		}
	}

	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
		// Routing Load packages all packages that go to and come from the basis
		// station
		// TODO no hello packages included
		if (line.contains("scalar")
				&& (line.contains("RREPSent:count")
						|| line.contains("RREQSent:count") || line
							.contains("RERRSentNow"))) {
			int pk = this.routingPackages.get(this.extractHostNumber(line));
			this.routingPackages.set(this.extractHostNumber(line),
					pk + this.extractInteger(line));
		}
	}

	protected void getIndividualResult() throws Exception {
		/*
		 * if (this.sentPackages.size() != this.routingPackages.size()) { throw
		 * new Exception("Wrong host count..."); }
		 */

		// Calculate Routing load: (Routing Packages / All Packages) * 100
		DoubleArrayList routingLoad = new DoubleArrayList();
		ArrayList<Double> myroutingLoad = new ArrayList<Double>();

		for (int i = 0; i < this.sentPackages.size(); i++) {
			Integer sum = this.routingPackages.get(i)
					+ this.sentPackages.get(i);

			if (sum != 0) {
				routingLoad.add(100.0 * this.routingPackages.get(i) / (sum));
				myroutingLoad.add(100.0 * this.routingPackages.get(i)
						/ (sum + 1.0));
			}
		}

		System.out.println("NewAvg. "
				+ myroutingLoad.stream().mapToDouble(value -> value).average());

		// Calculating standard deviation doesn't make sense, because it is a
		// calculation of overall received / sent packages.
		double mmean = 100
				* this.getSumOfReceivedPackages()
				/ (this.getSumOfSentPackages() + this
						.getSumOfReceivedPackages());

		System.out.println(mmean);

		double mean = Descriptive.mean(routingLoad);
		double variance = Descriptive.sampleVariance(routingLoad, mean);
		double standardDeviation = Descriptive.standardDeviation(variance);

		System.out.println("Routing Load: Mean: " + mean + " Var: " + variance
				+ "Std: " + standardDeviation);
	}

	@Override
	protected String getAnalyzerName() {
		return "Routing Load...";
	}
}
