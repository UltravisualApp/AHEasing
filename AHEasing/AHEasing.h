//
//  easing.h
//
//  Copyright (c) 2011, Auerhaus Development, LLC
//
//  This program is free software. It comes without any warranty, to
//  the extent permitted by applicable law. You can redistribute it
//  and/or modify it under the terms of the Do What The Fuck You Want
//  To Public License, Version 2, as published by Sam Hocevar. See
//  http://sam.zoy.org/wtfpl/COPYING for more details.
//

#import <CoreGraphics/CGBase.h>

#ifndef AH_EASING_H
#define AH_EASING_H

typedef CGFloat (*AHEasingFunction)(CGFloat);

// Linear interpolation (no easing)
CGFloat AHLinearInterpolation(CGFloat p);

// Quadratic easing; p^2
CGFloat AHQuadraticEaseIn(CGFloat p);
CGFloat AHQuadraticEaseOut(CGFloat p);
CGFloat AHQuadraticEaseInOut(CGFloat p);

// Cubic easing; p^3
CGFloat AHCubicEaseIn(CGFloat p);
CGFloat AHCubicEaseOut(CGFloat p);
CGFloat AHCubicEaseInOut(CGFloat p);

// Quartic easing; p^4
CGFloat AHQuarticEaseIn(CGFloat p);
CGFloat AHQuarticEaseOut(CGFloat p);
CGFloat AHQuarticEaseInOut(CGFloat p);

// Quintic easing; p^5
CGFloat AHQuinticEaseIn(CGFloat p);
CGFloat AHQuinticEaseOut(CGFloat p);
CGFloat AHQuinticEaseInOut(CGFloat p);

// Sine wave easing; sin(p * PI/2)
CGFloat AHSineEaseIn(CGFloat p);
CGFloat AHSineEaseOut(CGFloat p);
CGFloat AHSineEaseInOut(CGFloat p);

// Circular easing; sqrt(1 - p^2)
CGFloat AHCircularEaseIn(CGFloat p);
CGFloat AHCircularEaseOut(CGFloat p);
CGFloat AHCircularEaseInOut(CGFloat p);

// Exponential easing, base 2
CGFloat AHExponentialEaseIn(CGFloat p);
CGFloat AHExponentialEaseOut(CGFloat p);
CGFloat AHExponentialEaseInOut(CGFloat p);

// Exponentially-damped sine wave easing
CGFloat AHElasticEaseIn(CGFloat p);
CGFloat AHElasticEaseOut(CGFloat p);
CGFloat AHElasticEaseInOut(CGFloat p);

// Overshooting cubic easing;
CGFloat AHBackEaseIn(CGFloat p);
CGFloat AHBackEaseOut(CGFloat p);
CGFloat AHBackEaseInOut(CGFloat p);

// Exponentially-decaying bounce easing
CGFloat AHBounceEaseIn(CGFloat p);
CGFloat AHBounceEaseOut(CGFloat p);
CGFloat AHBounceEaseInOut(CGFloat p);

#endif