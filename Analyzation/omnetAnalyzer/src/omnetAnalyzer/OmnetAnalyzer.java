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

/**
 * 
 * This program analyzes the sca files of omnetpp
 * 
 * TODO excel output TODO comments
 * 
 * @author manuel kaspar
 *
 */
public class OmnetAnalyzer {
	/**
	 * How many hosts are in the simulation
	 */
	public static final int NR_OF_HOSTS = 65;

	/**
	 * How many repeats are set in omnetpp.ini
	 */
	public static final int NR_OF_REPEATS = 10;

	public static final double[] sendingIntervals = { 30, 1, 0.5, 0.1, 0.05 };

	/**
	 * What time interval of the simulation time is recorded to statistics (here
	 * time was 900)
	 */
	public static final int RECORDED_SIMULATION_TIME = 890;

	public static ArrayList<MyAnalyzer> myAnalyzers = new ArrayList<>();

	public static ArrayList<String> OUTPUT = new ArrayList<>();
	public static ArrayList<String> EXCEL_OUTPUT = new ArrayList<>();

	public static boolean verboseOutput = true;
	public static boolean excelOutput = false;

	public static void main(String[] args) {
		String directory = "";

		if (args.length == 0) {
			System.out
					.println("This program analyzes the .sca files of omnet "
							+ "that are in the given path.\nFirst parameter is path to the folder.");

			return;
		} else if (args.length == 1) {
			directory = args[0];
		} else if (args.length == 2) {
			if (!args[0].contains("v") && !args[0].contains("e")) {
				System.out
						.println("When additional arguments to the directory path are given, there are "
								+ "following options:\n-v for more explaining output\n"
								+ "-e for output for excel. Can also be combined...");

				return;
			} else {
				if (args[0].contains("e")) {
					excelOutput = true;
					verboseOutput = false;
				}
				if (args[0].contains("v")) {
					verboseOutput = true;
				}

				directory = args[1];
			}
		}

		myAnalyzers = getAnalyzers();

		ArrayList<File> files = readDirectory(directory);

		// Do for every .sca file in directory
		for (File file : files) {
			OmnetAnalyzer.OUTPUT.add("File " + file.getName());

			MyFileReader myFileReader = new MyFileReader(file, myAnalyzers);
			myFileReader.readFile();

			for (MyAnalyzer analyzer : myAnalyzers) {
				try {
					analyzer.getResult();

					OmnetAnalyzer.OUTPUT.add("");
				} catch (Exception e) {
					e.printStackTrace();
				}
			}

			OmnetAnalyzer.OUTPUT.add("");
		}

		if (verboseOutput)
			OmnetAnalyzer.printOutput(OmnetAnalyzer.OUTPUT);

		if (excelOutput)
			OmnetAnalyzer.printExcelOutput();
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

				// Compare for the first letter and sort by this to divide AODV
				// and D2DRS
				if (name1.charAt(0) > name2.charAt(0)) {
					return 1;
				} else if (name1.charAt(0) < name2.charAt(0)) {
					return -1;
				} else {
					// Compare by run number
					if (val1 > val2)
						return 1;
					else if (val2 > val1)
						return -1;
					else
						throw new RuntimeException("Same numbers of files... "
								+ val1);
				}
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

	private static void printOutput(ArrayList<String> output) {
		for (String o : output) {
			System.out.println(o);
		}
	}

	private static void printExcelOutput() {
		System.out.println("Excel-Output");
		System.out.println("");

		// Output data per analyzer
		int b = 0;
		for (MyAnalyzer analyzer : myAnalyzers) {
			System.out.println(analyzer.getAnalyzerName());
			System.out.print("Sending-Intervals/Repeat-Number\t");

			// Print Headline
			for (int i = 0; i < NR_OF_REPEATS; i++) {
				System.out.print(i + " mean\t" + i + " stddev\t");
			}
			System.out.println("");

			for (int i = 0; i < sendingIntervals.length; i++) {
				System.out.print(sendingIntervals[i] + "\t\t\t\t");

				for (int x = 0; x < NR_OF_REPEATS * 2; x++) {
					System.out.print(EXCEL_OUTPUT.get((b * i) + x) + "\t\t");
				}

				System.out.println("");
			}

			b++;
		}

	}
}
