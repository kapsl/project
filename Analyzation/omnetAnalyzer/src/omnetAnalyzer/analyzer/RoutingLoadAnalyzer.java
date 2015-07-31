package omnetAnalyzer.analyzer;

import java.io.BufferedReader;
import java.util.ArrayList;

import omnetAnalyzer.MyAnalyzer;
import cern.colt.list.DoubleArrayList;

public class RoutingLoadAnalyzer extends MyAnalyzer {
	private ArrayList<Integer> routingPackages = new ArrayList<Integer>();

	public RoutingLoadAnalyzer() {
		super();

		this.initializeArrayForHosts(this.routingPackages, 0);
	}

	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
		// Routing Load packages all packages that go to and come from the basis
		// station
		if (line.contains("scalar")
				&& (line.contains("RREPSent:count")
						|| line.contains("RREQSent:count")
						|| line.contains("RERRSentNow") || line
							.contains("HelloMsg:count"))) {
			int pk = this.routingPackages.get(this.extractHostNumber(line));
			this.routingPackages.set(this.extractHostNumber(line),
					pk + this.extractInteger(line));
		}
	}

	protected void getIndividualResult() throws Exception {
		// Calculate Routing load: (Routing Packages / All Packages) * 100
		DoubleArrayList normalizedRoutingPackageNr = new DoubleArrayList();

		for (int i = 0; i < this.routingPackages.size(); i++) {
			int sum = this.sentPackages.get(i) + this.routingPackages.get(i);

			// Add this value nr. of received packages for this host times, to
			// get weighted middle
			for (int x = 0; x < sum; x++) {
				if (sum != 0)
					normalizedRoutingPackageNr
							.add(100.0
									* Double.valueOf(this.routingPackages
											.get(i)) / sum);
			}
		}

		this.printStatistics(normalizedRoutingPackageNr);
	}
	
	@Override
	public void reset() {
		super.reset();
		
		this.initializeArrayForHosts(this.routingPackages, 0);
	}

	@Override
	protected String getAnalyzerName() {
		return "Routing Load...";
	}
}
