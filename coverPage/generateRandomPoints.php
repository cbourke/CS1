<?php

function purebell($min,$max,$std_deviation,$step=.001) {
  $rand1 = (float)mt_rand()/(float)mt_getrandmax();
  $rand2 = (float)mt_rand()/(float)mt_getrandmax();
  $gaussian_number = sqrt(-2 * log($rand1)) * cos(2 * M_PI * $rand2);
  $mean = ($max + $min) / 2;
  $random_number = ($gaussian_number * $std_deviation) + $mean;
  $random_number = round($random_number / $step) * $step;
  if($random_number < $min || $random_number > $max) {
    $random_number = purebell($min, $max,$std_deviation);
  }
  return $random_number;
}


$radius = 30;
$n = 500;
$center_x = 7.75;
$center_y = -15;
$opacity = .1;

//$xs = array_distribute(0, $n, -10, 10);
//$ys = array_distribute(0, $n, -10, 10);

$points = array();

for($i=0; $i<$n; $i++) {
  $x = purebell(-9.5, 9.5, 1.25);
  $y = purebell(-9.5, 9.5, 1.25);  
  $point = array($x+$center_x, $y+$center_y);
  $points[] = $point;
}

$i=1;
foreach($points as $point) {
  $str = "\\draw[black,fill=black,opacity=".$opacity."] (".$point[0].", ".$point[1].") circle (3pt);\n";
  print $str;
  $i++;
}



?>