package omnetAnalyzer;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

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
	 * What time interval of the simulation time is recorded to statistics (here
	 * time was 900)
	 */
	public static final int RECORDED_SIMULATION_TIME = 890;

	public static void main(String[] args) {
		ArrayList<MyAnalyzer> myAnalyzers = getAnalyzers();

		ArrayList<File> files = readDirectory("./");

		// Do for every .sca file in directory
		for (File file : files) {
			System.out.println("File " + file.getName());
			
			MyFileReader myFileReader = new MyFileReader(file, myAnalyzers);
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

	/**
	 * Read the given directory and get back right sorted .sca files
	 */
	private static ArrayList<File> readDirectory(String path) {
		ArrayList<File> filesToAnalyze = new ArrayList<>();

		try {
			Files.walk(Paths.get(path))
					.forEach(
							filePath -> {
								String filename = String.valueOf(filePath
										.getFileName());

								if (Files.isRegularFile(filePath)
										&& filename.contains(".sca")) {
									filesToAnalyze.add(filePath.toFile());
								}
							});
		} catch (IOException e1) {
			e1.printStackTrace();
		}

		// Sorting
		Collections.sort(filesToAnalyze, new Comparator<File>() {
			@Override
			public int compare(File file1, File file2) {
				String name1 = file1.getName();
				int val1 = Integer.valueOf(name1.substring(
						name1.lastIndexOf('-') + 1, name1.lastIndexOf('.')));

				String name2 = file2.getName();
				int val2 = Integer.valueOf(name2.substring(
						name2.lastIndexOf('-') + 1, name2.lastIndexOf('.')));

				if (val1 > val2)
					return 1;
				else if (val2 > val1)
					return -1;
				else
					throw new RuntimeException("Same numbers of files... "
							+ val1);
			}
		});

		return filesToAnalyze;
	}

	/**
	 * What do we want to analyzed
	 */
	private static ArrayList<MyAnalyzer> getAnalyzers() {
		ArrayList<MyAnalyzer> myAnalyzers = new ArrayList<>();

		myAnalyzers.add(new PacketLossAnalyzer());
		myAnalyzers.add(new RoutingLoadAnalyzer());
		myAnalyzers.add(new EndToEndDelayAnalyzer());
		myAnalyzers.add(new ThroughputAnalyzer());

		return myAnalyzers;
	}
}
