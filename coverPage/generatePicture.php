<?php

$greek = array(
"\\alpha","\\theta","\\tau",
		"\\beta","\\vartheta","\\pi","\\upsilon",
			"\\gamma","\\gamma","\\varpi","\\phi",
				"\\delta","\\kappa","\\rho","\\varphi",
					"\\epsilon","\\lambda","\\varrho","\\chi",
						"\\varepsilon","\\mu","\\sigma","\\psi",
							"\\zeta","\\nu","\\varsigma","\\omega",
								"\\eta","\\xi","\\Gamma","\\Lambda",
								    "\\Sigma","\\Psi",
									"\\Delta","\\Xi","\\Upsilon","\\Omega",
										"\\Theta","\\Pi","\\Phi"
);

$radius = 30;
$n = 50;
$theta = 2 * M_PI / $n;
$center_x = 7.75;
$center_y = -15;
$opacity = .1;

$points = array();

for($i=0; $i<$n; $i++) {
  $x = $radius * cos($i * $theta) + $center_x;
  $y = $radius * sin($i * $theta) + $center_y;
  $point = array($x, $y);
  $points[] = $point;
}

$i=1;
foreach($points as $point) {
  $symbol = $greek[array_rand($greek, 1)];
  $str = "\\node[draw,circle,opacity=".$opacity."] (a".$i.") at (".$point[0].", ".$point[1].") {\$".$symbol."\$}; \n";
  print $str;
  $i++;
}

for($i=1; $i<=$n; $i++) {
  for($j=$i+1; $j<=$n; $j++) {
    $str = "\\draw[opacity=".$opacity."] (a".$i.") -- (a".$j.");\n";
    print $str;
  }
}

?>