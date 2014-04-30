//
//  easing.c
//
//  Copyright (c) 2011, Auerhaus Development, LLC
//
//  This program is free software. It comes without any warranty, to
//  the extent permitted by applicable law. You can redistribute it
//  and/or modify it under the terms of the Do What The Fuck You Want
//  To Public License, Version 2, as published by Sam Hocevar. See
//  http://sam.zoy.org/wtfpl/COPYING for more details.
//

#import <tgmath.h>
#include "AHEasing.h"

// Modeled after the line y = x
CGFloat AHLinearInterpolation(CGFloat p)
{
	return p;
}

// Modeled after the parabola y = x^2
CGFloat AHQuadraticEaseIn(CGFloat p)
{
	return p * p;
}

// Modeled after the parabola y = -x^2 + 2x
CGFloat AHQuadraticEaseOut(CGFloat p)
{
	return -(p * (p - 2));
}

// Modeled after the piecewise quadratic
// y = (1/2)((2x)^2)             ; [0, 0.5)
// y = -(1/2)((2x-1)*(2x-3) - 1) ; [0.5, 1]
CGFloat AHQuadraticEaseInOut(CGFloat p)
{
	if(p < 0.5f)
	{
		return 2 * p * p;
	}
	else
	{
		return (-2 * p * p) + (4 * p) - 1;
	}
}

// Modeled after the cubic y = x^3
CGFloat AHCubicEaseIn(CGFloat p)
{
	return p * p * p;
}

// Modeled after the cubic y = (x - 1)^3 + 1
CGFloat AHCubicEaseOut(CGFloat p)
{
	CGFloat f = (p - 1);
	return f * f * f + 1;
}

// Modeled after the piecewise cubic
// y = (1/2)((2x)^3)       ; [0, 0.5)
// y = (1/2)((2x-2)^3 + 2) ; [0.5, 1]
CGFloat AHCubicEaseInOut(CGFloat p)
{
	if(p < 0.5f)
	{
		return 4 * p * p * p;
	}
	else
	{
		CGFloat f = ((2 * p) - 2);
		return 0.5f * f * f * f + 1;
	}
}

// Modeled after the quartic x^4
CGFloat AHQuarticEaseIn(CGFloat p)
{
	return p * p * p * p;
}

// Modeled after the quartic y = 1 - (x - 1)^4
CGFloat AHQuarticEaseOut(CGFloat p)
{
	CGFloat f = (p - 1);
	return f * f * f * (1 - p) + 1;
}

// Modeled after the piecewise quartic
// y = (1/2)((2x)^4)        ; [0, 0.5)
// y = -(1/2)((2x-2)^4 - 2) ; [0.5, 1]
CGFloat AHQuarticEaseInOut(CGFloat p)
{
	if(p < 0.5)
	{
		return 8 * p * p * p * p;
	}
	else
	{
		CGFloat f = (p - 1);
		return -8 * f * f * f * f + 1;
	}
}

// Modeled after the quintic y = x^5
CGFloat AHQuinticEaseIn(CGFloat p)
{
	return p * p * p * p * p;
}

// Modeled after the quintic y = (x - 1)^5 + 1
CGFloat AHQuinticEaseOut(CGFloat p)
{
	CGFloat f = (p - 1);
	return f * f * f * f * f + 1;
}

// Modeled after the piecewise quintic
// y = (1/2)((2x)^5)       ; [0, 0.5)
// y = (1/2)((2x-2)^5 + 2) ; [0.5, 1]
CGFloat AHQuinticEaseInOut(CGFloat p)
{
	if(p < 0.5)
	{
		return 16 * p * p * p * p * p;
	}
	else
	{
		CGFloat f = ((2 * p) - 2);
		return  0.5f * f * f * f * f * f + 1;
	}
}

// Modeled after quarter-cycle of sine wave
CGFloat AHSineEaseIn(CGFloat p)
{
	return sin((p - 1) * (CGFloat)(M_PI_2)) + 1;
}

// Modeled after quarter-cycle of sine wave (different phase)
CGFloat AHSineEaseOut(CGFloat p)
{
	return sin(p * (CGFloat)(M_PI_2));
}

// Modeled after half sine wave
CGFloat AHSineEaseInOut(CGFloat p)
{
	return 0.5f * (1 - cos(p * (CGFloat)(M_PI)));
}

// Modeled after shifted quadrant IV of unit circle
CGFloat AHCircularEaseIn(CGFloat p)
{
	return 1 - sqrt(1 - (p * p));
}

// Modeled after shifted quadrant II of unit circle
CGFloat AHCircularEaseOut(CGFloat p)
{
	return sqrt((2 - p) * p);
}

// Modeled after the piecewise circular function
// y = (1/2)(1 - sqrt(1 - 4x^2))           ; [0, 0.5)
// y = (1/2)(sqrt(-(2x - 3)*(2x - 1)) + 1) ; [0.5, 1]
CGFloat AHCircularEaseInOut(CGFloat p)
{
	if(p < 0.5)
	{
		return 0.5f * (1 - sqrt(1 - 4 * (p * p)));
	}
	else
	{
		return 0.5f * (sqrt(-((2 * p) - 3) * ((2 * p) - 1)) + 1);
	}
}

// Modeled after the exponential function y = 2^(10(x - 1))
CGFloat AHExponentialEaseIn(CGFloat p)
{
	return (p == 0.f) ? p : pow(2.f, 10 * (p - 1));
}

// Modeled after the exponential function y = -2^(-10x) + 1
CGFloat AHExponentialEaseOut(CGFloat p)
{
	return (p == 1.f) ? p : 1 - pow(2.f, -10 * p);
}

// Modeled after the piecewise exponential
// y = (1/2)2^(10(2x - 1))         ; [0,0.5)
// y = -(1/2)*2^(-10(2x - 1))) + 1 ; [0.5,1]
CGFloat AHExponentialEaseInOut(CGFloat p)
{
	if(p == 0.f || p == 1.f) return p;
	
	if(p < 0.5f)
	{
		return 0.5f * pow(2.f, (20 * p) - 10);
	}
	else
	{
		return -0.5f * pow(2.f, (-20 * p) + 10) + 1;
	}
}

// Modeled after the damped sine wave y = sin(13pi/2*x)*pow(2, 10 * (x - 1))
CGFloat AHElasticEaseIn(CGFloat p)
{
	return sin(13 * (CGFloat)(M_PI_2) * p) * pow(2.f, 10 * (p - 1));
}

// Modeled after the damped sine wave y = sin(-13pi/2*(x + 1))*pow(2, -10x) + 1
CGFloat AHElasticEaseOut(CGFloat p)
{
	return sin(-13 * (CGFloat)(M_PI_2) * (p + 1)) * pow(2.f, -10 * p) + 1;
}

// Modeled after the piecewise exponentially-damped sine wave:
// y = (1/2)*sin(13pi/2*(2*x))*pow(2, 10 * ((2*x) - 1))      ; [0,0.5)
// y = (1/2)*(sin(-13pi/2*((2x-1)+1))*pow(2,-10(2*x-1)) + 2) ; [0.5, 1]
CGFloat AHElasticEaseInOut(CGFloat p)
{
	if(p < 0.5f)
	{
		return 0.5f * sin(13.f * (CGFloat)(M_PI_2) * (2.f * p)) * pow(2.f, 10.f * ((2.f * p) - 1));
	}
	else
	{
		return 0.5f * (sin(-13.f * (CGFloat)(M_PI_2) * ((2.f * p - 1) + 1)) * pow(2.f, -10.f * (2.f * p - 1.f)) + 2.f);
	}
}

// Modeled after the overshooting cubic y = x^3-x*sin(x*pi)
CGFloat AHBackEaseIn(CGFloat p)
{
	return p * p * p - p * sin(p * (CGFloat)(M_PI));
}

// Modeled after overshooting cubic y = 1-((1-x)^3-(1-x)*sin((1-x)*pi))
CGFloat AHBackEaseOut(CGFloat p)
{
	CGFloat f = (1 - p);
	return 1 - (f * f * f - f * sin(f * (CGFloat)(M_PI)));
}

// Modeled after the piecewise overshooting cubic function:
// y = (1/2)*((2x)^3-(2x)*sin(2*x*pi))           ; [0, 0.5)
// y = (1/2)*(1-((1-x)^3-(1-x)*sin((1-x)*pi))+1) ; [0.5, 1]
CGFloat AHBackEaseInOut(CGFloat p)
{
	if(p < 0.5)
	{
		CGFloat f = 2 * p;
		return 0.5f * (f * f * f - f * sin(f * (CGFloat)(M_PI)));
	}
	else
	{
		CGFloat f = (1 - (2*p - 1));
		return 0.5f * (1 - (f * f * f - f * sin(f * (CGFloat)(M_PI)))) + 0.5f;
	}
}

CGFloat AHBounceEaseIn(CGFloat p)
{
	return 1 - AHBounceEaseOut(1 - p);
}

CGFloat AHBounceEaseOut(CGFloat p)
{
	if(p < 4/11.f)
	{
		return (121 * p * p)/16.f;
	}
	else if(p < 8/11.f)
	{
		return (363/40.f * p * p) - (99/10.f * p) + 17/5.f;
	}
	else if(p < 9/10.f)
	{
		return (4356/361.f * p * p) - (35442/1805.f * p) + 16061/1805.f;
	}
	else
	{
		return (54/5.f * p * p) - (513/25.f * p) + 268/25.f;
	}
}

CGFloat AHBounceEaseInOut(CGFloat p)
{
	if(p < 0.5f)
	{
		return 0.5f * AHBounceEaseIn(p*2);
	}
	else
	{
		return 0.5f * AHBounceEaseOut(p * 2 - 1) + 0.5f;
	}
}
