package omnetAnalyzer.analyzer;

import java.io.BufferedReader;

import omnetAnalyzer.MyAnalyzer;
import omnetAnalyzer.OmnetAnalyzer;
import cern.colt.list.DoubleArrayList;

public class ThroughputAnalyzer extends MyAnalyzer {
	@Override
	protected void parseIndividualLine(String line, BufferedReader br) {
	}

	protected void getIndividualResult() throws Exception {
		DoubleArrayList meanThroughput = new DoubleArrayList();
		
		for (int i = 0; i < this.receivedPackages.size(); i++) {
			// *512 Message length of udp packages is 512 bytes
			// :890 when we have 900s simulation time, the first 10 seconds are cut
			// :i the number of sending, receiving hosts
			// :1024 Bytes to Kilobytes
			if (this.receivedPackages.get(i) != 0.0) {
				double throughputPerHost = this.receivedPackages.get(i) * 512.0
						/ OmnetAnalyzer.RECORDED_SIMULATION_TIME / 1024;
				meanThroughput.add(throughputPerHost);
			}
		}

		this.printStatistics(meanThroughput);
	}

	@Override
	protected String getAnalyzerName() {
		return "Throughput...";
	}
}
