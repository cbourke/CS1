<?php
class Student {

  private $firstName;
  private $lastName;
  private $id;
  private $gpa;
  private $dateOfBirth;
  private $schedule;

  public function __construct($firstName, $lastName, $id = 0, $gpa = 0.0,
                              $dateOfBirth = null, $schedule = array()) {
    $this->firstName = $firstName;
    $this->lastName  = $lastName;
    $this->id = $id;
    $this->gpa = $gpa;
    $this->dateOfBirth = new DateTime($dateOfBirth);
    $this->schedule = $schedule;
  }

  public function __toString() {
    return $this->getFormattedName() . " born " .
           $this->dateOfBirth->format("Y-m-d");
  }

  /**
   * Returns a formatted String of the Student's
   * name as Last, First.
   */
  public function getFormattedName() {
    return $this->lastName . ", " . $this->firstName;
  }

  /**
   * Scales the GPA, which is assumed to be on a
   * 4.0 scale to a percentage.
   */
  public function getGpaAsPercentage() {
    return $this->gpa / 4.0;
  }

  public function getFirstName() {
    return $this->firstName;
  }

  public function getLastName() {
    return $this->lastName;
  }

  public function getId() {
    return $this->id;
  }

  public function getGpa() {
    return $this->gpa;
  }

  public function addCourse($c) {
    $this->schedule[] = $c;
  }

}

?>
