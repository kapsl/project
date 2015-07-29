package omnetAnalyzer;

import java.util.ArrayList;

import omnetAnalyzer.analyzer.EndToEndDelayAnalyzer;
import omnetAnalyzer.analyzer.PacketLossAnalyzer;
import omnetAnalyzer.analyzer.RoutingLoadAnalyzer;
import omnetAnalyzer.analyzer.ThroughputAnalyzer;

public class OmnetAnalyzer {
	/**
	 * How many hosts are in the simulation
	 */
	public static final int NR_OF_HOSTS = 65;
	
	/**
	 * What time interval of the simulation time is recorded to statistics (here time was 900)
	 */
	public static final int RECORDED_SIMULATION_TIME = 890;
	
	public static void main(String[] args) {
		ArrayList<MyAnalyzer> myAnalyzers = new ArrayList<>();
		myAnalyzers.add(new PacketLossAnalyzer());
		myAnalyzers.add(new RoutingLoadAnalyzer());
		myAnalyzers.add(new EndToEndDelayAnalyzer());
		myAnalyzers.add(new ThroughputAnalyzer());
		
		MyFileReader myFileReader = new MyFileReader("./General-3.sca", myAnalyzers);
		myFileReader.readFile();
		
		for (MyAnalyzer analyzer : myAnalyzers) {
			try {
				analyzer.getResult();
				
				System.out.println("");
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
}
