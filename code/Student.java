package unl.cse;

public class Student {

  private String firstName;
  private String lastName;
  private int id;
  private double gpa;
  
  public Student(String firstName, String lastName, int id, double gpa) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.id = id;
    this.gpa = gpa;
  }
  
  public Student() {
    this(null, null, 0, 0.0);
  }

  public Student(String firstName, String lastName) {
    this(firstName, lastName, 0, 0.0);
  }

  public String getFirstName() {
    return firstName;
  }
  
  public String getLastName() {
    return lastName;
  }
  
  public int getId() {
    return id;
  }
  
  public double getGpa() {
    return gpa;
  }
  
  /**
   * Returns a formatted String of the Student's
   * name as Last, First.
   */
  public String getFormattedName() {
    return lastName + ", " + firstName;
  }
  
  /**
   * Scales the GPA, which is assumed to be on a
   * 4.0 scale to a percentage.
   */
  public double getGpaAsPercentage() {
    return gpa / 4.0;
  }
  
  @Override
  public String toString() {
    return String.format("%s, %s (ID = %d); %.2f", 
             this.lastName,
             this.firstName,
             this.id,
             this.gpa);
  }
  
  @Override
  public int hashCode() {
    final int prime = 31;
    int result = 1;
    result = prime * result + ((firstName == null) ? 0 : firstName.hashCode());
    long temp;
    temp = Double.doubleToLongBits(gpa);
    result = prime * result + (int) (temp ^ (temp >>> 32));
    result = prime * result + id;
    result = prime * result + ((lastName == null) ? 0 : lastName.hashCode());
    return result;
  }
  
  
  @Override
  public boolean equals(Object obj) {
    if (this == obj) {
      return true;
    }
    if (obj == null) {
      return false;
    }
    if (!(obj instanceof Student)) {
      return false;
    }
    Student other = (Student) obj;
    if (firstName == null) {
      if (other.firstName != null) {
        return false;
      }
    } else if (!firstName.equals(other.firstName)) {
      return false;
    }
    if (Double.doubleToLongBits(gpa) != Double.doubleToLongBits(other.gpa)) {
      return false;
    }
    if (id != other.id) {
      return false;
    }
    if (lastName == null) {
      if (other.lastName != null) {
        return false;
      }
    } else if (!lastName.equals(other.lastName)) {
      return false;
    }
    return true;
  }


  
}
