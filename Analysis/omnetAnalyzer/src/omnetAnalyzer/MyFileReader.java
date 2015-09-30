package omnetAnalyzer;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

/**
 * 
 * Read an .sca file and forward to Analyzers
 * 
 * @author manuel
 *
 */
public class MyFileReader {
	private File file;
	private ArrayList<MyAnalyzer> myAnalyzers;
	
	public MyFileReader(File fileName, ArrayList<MyAnalyzer> myAnalyzers) {
		this.file = fileName;
		this.myAnalyzers = myAnalyzers;
	}
	
	public void readFile() {
		try (BufferedReader br = new BufferedReader(new FileReader(this.file))) {
		    String line;
		    
		    while ((line = br.readLine()) != null) {
		    	for (MyAnalyzer analyzer : this.myAnalyzers) {
		    		analyzer.parseLine(line, br);
		    	}
		    }
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
