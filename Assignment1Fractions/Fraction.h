/**
* @file <source.cpp>
*
* @author  <Ali Emir Samlioglu>
* @version <1.0>
*
* change log
* name      date 14-01-2020
*
*
* [file, auther, version, and change log are not necessary with
*    modern source code management system]
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
*
* @section DESCRIPTION
*  < brief description of the purpose of this file >
*	Fraction class with operator overloading that passes each test case.
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#pragma once
class Fraction
{

/*private:
	int numerator;
	int denominator;*/
public:
	int numerator;
	int denominator;

	/**************************
	* CONSTRUCTOR             *
	***************************/
	Fraction();
	Fraction(int n);
	Fraction(int n, int d);

	/*******************************
	* LOGICAL OPERATOR OVERLOADING *
	********************************/
	bool operator == (const Fraction& other) const;
	bool operator != (const Fraction& other) const;
	bool operator < (const Fraction& other) const;
	bool operator <= (const Fraction& other) const;
	bool operator > (const Fraction& other) const;
	bool operator >= (const Fraction& other) const;

	/*********************************************
	* FRACTION ADDITION "+" AND "+=" OVERLOADING *
	**********************************************/
	Fraction operator +(const Fraction& other);
	Fraction& operator +=(const Fraction& other);

	/************************************************
	* FRACTION SUBTRACTION "-" AND "-=" OVERLOADING *
	*************************************************/
	Fraction operator -(const Fraction& other);
	Fraction& operator -=(const Fraction& other);

	/***************************************************
	* FRACTION MULTIPLICATION "*" AND "*=" OVERLOADING *
	****************************************************/
	Fraction operator *(const Fraction& other);
	Fraction& operator *=(const Fraction& other);

	/*********************************************
	* FRACTION DIVISION "/" AND "/=" OVERLOADING *
	**********************************************/
	Fraction operator /(const Fraction& other);
	Fraction& operator /=(const Fraction& other);

	/*******************************************
	* INPUT AND OUTPUT STREAM FRIEND FUNCTIONS *
	********************************************/
	friend std::ostream& operator << (std::ostream& os, const Fraction& frac);
	friend std::istream& operator >> (std::istream& is, Fraction& frac);
};

/**********************************************************************************
* GLOBAL FUNCTIONS FOR LOGICAL OPERATORS ("<" AND ">") AND MATHEMATICAL OPERATORS *
***********************************************************************************/
bool operator < (int x, Fraction& other) ;
bool operator > (int x, Fraction& other);

Fraction operator +(int x, Fraction& other);
Fraction operator +( Fraction& other,int x);

Fraction operator +=(int x, Fraction& other);
Fraction operator +=(Fraction& other, int x);

Fraction operator -(int x, Fraction& other);
Fraction operator -(Fraction& other, int x);

Fraction operator -=(int x, Fraction& other);
Fraction operator -=(Fraction& other, int x);

Fraction operator *(int x, Fraction& other);
Fraction operator *(Fraction& other, int x);

Fraction operator *=(int x, Fraction& other);
Fraction operator *=(Fraction& other, int x);

Fraction operator /(int x, Fraction& other);
Fraction operator /(Fraction& other, int x);

Fraction operator /=(int x, Fraction& other);
Fraction operator /=(Fraction& other, int x);