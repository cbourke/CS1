package unl.cse.student;

import java.util.ArrayList;
import java.util.List;

public class Course {
	
	private String number;
	private String title;
	private List<Student> roster;
	/**
	 * @param number
	 * @param title
	 * @param roster
	 */
	public Course(String number, String title, List<Student> roster) {
		this.number = number;
		this.title = title;
		this.roster = new ArrayList<Student>(roster);
	}
	
	public Course(String number, String title) {
		this(number, title, new ArrayList<Student>());
	}
	
	public void enrollStudent(Student s) {
		if(!this.roster.contains(s)) {
			this.roster.add(s);
		} else {
			//throw an exception, do nothing, return false maybe, etc.etc.
		}
	}

	@Override
	public String toString() {
		return "Course [number=" + number + ", title=" + title + ", roster="
				+ roster + "]";
	}
	
	

}
