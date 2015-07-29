package omnetAnalyzer;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class MyFileReader {
	private String fileName;
	private ArrayList<MyAnalyzer> myAnalyzers;
	
	public MyFileReader(String fileName, ArrayList<MyAnalyzer> myAnalyzers) {
		this.fileName = fileName;
		this.myAnalyzers = myAnalyzers;
	}
	
	public void readFile() {
		try (BufferedReader br = new BufferedReader(new FileReader(this.fileName))) {
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
