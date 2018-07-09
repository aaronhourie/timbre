
color ([0.1, 0.1, 0.1]) union() {
    
    difference() { 
        cube([5, 3 + 1/4, 2 + 1/4]); 
        translate ([1/8, 1/8, 1/8]) cube([4 + 3/4, 3, 2.3]);
        translate([1/4-0.5, 1/4 + 1.375, 1.865]) cube([0.8, 0.75, 0.33]);
        translate([1 + 4/32, 3, 1.9+1/32]) cube([1/2, 7/16, 3/16]);
        translate([1.8, -0.1, 1.9]) cube([1.2, 1/2, 1/2]);
    };
    translate([1/4, 1/4, 0]) {
        translate([0, 0, 0]) cube([1/4, 1/4, 1.9]);
        translate([3-1/4, 0, 0]) cube([1/4, 1/4, 1.9]);
        translate([0, 2.65-1/4, 0]) cube([1/4, 1/4, 1.9]);
        translate([3-1/4, 2.65-1/4, 0]) cube([1/4, 1/4, 1.9]);
    }

    translate([4+5/8, 3-1/8, 0]) cube([1/4, 1/4, 2 + 1/4]);
    translate([4+5/8, 1/8, 0]) cube([1/4, 1/4, 2 + 1/4]);
    translate([1/8, 3-1/8, 2+1/8]) cube([1/4, 1/4, 1/8]);
}

color([0, 0.5, 1]) 
translate([0, 0, 2+1/4]) 
{
    union()
    {
        difference() {
            cube ([5, 3+1/4, 1/8]);
            translate ([-1/16, -1/16, -1/16]) {
                cube ([1.75, 1, 1/4]);
            }
        }
        
        linear_extrude(height=0.2)
        translate([0, 2, 0.21]) 
        scale([0.1, 0.1, 0.4]) 
        {
            text("Timbre");
        }
    }
}
/**
translate([1/4, 1/4, 1.9]) {
    color([0, 1, 0]) cube ([3, 2.65, 1/16]);
    
    translate([-0.5, 1.5, 0]) color([0.5, 0.5, 0.5]) cube([0.75, 0.5, 0.25]);
    
    translate([-0.125, 0.25, 0]) color([0.1, 0.1, 0.2]) cube([1.25, 0.25, 0.125]);
    
    translate([3, 1.25, 0]) color([0.8, 0.8, 0.0]) cube([3/8, 1.25, 1/16]);
    
    translate([1, 2.7-3/8, 1/16]) color([0.5, 0.5, 0.5]) cube([1/4, 3/8, 1/8]);
    
    translate([1+10/16, 0, 1/16]) color([0.1, 0.1, 0.1]) cube([3/8, 1/2, 7/32]);
    
    translate([2+1/4, 0, 1/16]) color([0.1, 0.1, 0.1]) cube([3/8, 1/2, 7/32]);
}
**/