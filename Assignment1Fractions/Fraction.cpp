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

#include "pch.h"
#include "Fraction.h"
#include <algorithm>
#include <numeric>

/**************************
* CONSTRUCTORS            *
***************************/
Fraction::Fraction()
{

}
Fraction::Fraction(int n)
{
	numerator = n;
	denominator = 1;
	int tmp = std::gcd(numerator, denominator);
	numerator /= tmp;
	denominator /= tmp;
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
}
Fraction::Fraction(int n, int d) : numerator(n), denominator(d)
{
	int tmp = std::gcd(numerator, denominator);
	numerator /= tmp;
	denominator /= tmp;
	if (denominator < 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	if (d == 0)
	{
		throw std::out_of_range("denominator cannot be 0");
	}
}

/*******************************
* LOGICAL OPERATOR OVERLOADING *
********************************/
bool Fraction::operator==(const Fraction& other) const
{
	return (numerator * other.denominator == denominator * other.numerator);
}

bool Fraction::operator!=(const Fraction& other) const
{
	return !(numerator * other.denominator == denominator * other.numerator);
}

bool Fraction::operator<(const Fraction& other) const
{
	return (numerator * other.denominator < denominator * other.numerator);
}

bool Fraction::operator<=(const Fraction& other) const
{
	return (numerator * other.denominator <= denominator * other.numerator);
}

bool Fraction::operator>(const Fraction& other) const
{
	return (numerator * other.denominator > denominator* other.numerator);
}

bool Fraction::operator>=(const Fraction& other) const
{
	return (numerator * other.denominator >= denominator * other.numerator);
}

/*********************************************
* FRACTION ADDITION "+" AND "+=" OVERLOADING *
**********************************************/
Fraction Fraction::operator+(const Fraction& other)
{
	Fraction tmp;
	tmp.numerator = ((numerator * other.denominator) + (other.numerator * denominator));
	tmp.denominator = denominator * other.denominator;
	return tmp;
}

Fraction& Fraction::operator+=(const Fraction& other)
{

	numerator = ((numerator * other.denominator) + (other.numerator * denominator));
	denominator = denominator * other.denominator;
	Fraction* tmp = this;
	return *tmp;
}

/************************************************
* FRACTION SUBTRACTION "-" AND "-=" OVERLOADING *
*************************************************/
Fraction Fraction::operator-(const Fraction& other)
{
	Fraction tmp;
	tmp.numerator = ((numerator * other.denominator) - (other.numerator * denominator));
	tmp.denominator = denominator * other.denominator;
	return tmp;
}

Fraction& Fraction::operator-=(const Fraction& other)
{

	numerator = ((numerator * other.denominator) - (other.numerator * denominator));
	denominator = denominator * other.denominator;
	Fraction* tmp = this;
	return *tmp;
}

/***************************************************
* FRACTION MULTIPLICATION "*" AND "*=" OVERLOADING *
****************************************************/
Fraction Fraction::operator*(const Fraction& other)
{
	numerator *= other.numerator;
	denominator *= other.denominator;
	if (numerator > 0 && denominator > 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	Fraction* tmp = this;
	return *tmp;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
	numerator *= other.numerator;
	denominator *= other.denominator;
	if (numerator > 0 && denominator > 0)
	{
		numerator *= -1;
		denominator *= -1;
	}
	Fraction* tmp = this;
	return *tmp;
}

/*********************************************
* FRACTION DIVISION "/" AND "/=" OVERLOADING *
**********************************************/
Fraction Fraction::operator/(const Fraction& other)
{
	Fraction tmp(other.denominator, other.numerator);
	this->numerator *= tmp.numerator;
	this->denominator *= tmp.denominator;
	if (this->numerator < 0 && this->denominator < 0)
	{
		this->numerator *= -1;
		this->denominator *= -1;
	}
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
	Fraction tmp(other.denominator, other.numerator);
	this->numerator *= tmp.numerator;
	this->denominator *= tmp.denominator;
	if (this->numerator < 0 && this->denominator < 0)
	{
		this->numerator *= -1;
		this->denominator *= -1;
	}
	return *this;
}

/*******************************************
* INPUT AND OUTPUT STREAM FRIEND FUNCTIONS *
********************************************/
/*
 * FIX THE OCCURING PROBLEM BELOW 
 */
std::ostream& operator<<(std::ostream& os, const Fraction& frac)
{

	os << frac.numerator << "/" << frac.denominator;
	return os;
}
/*
 * FIX THE OCCURING PROBLEM BELOW
 */
std::istream& operator>>(std::istream& is, Fraction& frac)
{

	char L;
	is >> frac.numerator >> L >> frac.denominator;
	return is;
}

/**********************************************************************************
* GLOBAL FUNCTIONS FOR LOGICAL OPERATORS ("<" AND ">") AND MATHEMATICAL OPERATORS *
***********************************************************************************/
bool operator<(int x, Fraction& other)
{
	return (x < other.numerator /other.denominator);
}

bool operator>(int x, Fraction& other)
{
	return (x > other.numerator / other.denominator);
}

/***********
 *ADDITION *
 ***********/
Fraction operator+(int x, Fraction& other)
{
	Fraction tmp(x);
	tmp.numerator = (other.numerator + (x * other.denominator));
	tmp.denominator *= other.denominator;
	return tmp;
}

Fraction operator+(Fraction& other, int x)
{
	Fraction tmp(x);
	tmp.numerator = (other.numerator + (x * other.denominator));
	tmp.denominator *= other.denominator;
	return tmp;
}

Fraction operator+=(int x, Fraction& other)
{
	other.numerator += (x * other.denominator);
	return other;
}

Fraction operator+=(Fraction& other, int x)
{
	other.numerator += (x * other.denominator);
	return other;
}

/**************
 *SUBTRACTION *
 **************/
Fraction operator-(int x, Fraction& other)
{
	Fraction tmp(x);
	tmp.denominator *= other.denominator;
	tmp.numerator = (tmp.numerator * other.denominator) - other.numerator;
	return tmp;
}

Fraction operator-(Fraction& other, int x)
{
	Fraction tmp(x);
	tmp.denominator *= other.denominator;
	tmp.numerator = other.numerator - (tmp.numerator * other.denominator) ;
	return tmp;
}

Fraction operator-=(int x, Fraction& other)
{
	other.numerator = other.numerator - (x * other.denominator);
	return other;
}

Fraction operator-=(Fraction& other, int x)
{
	other.numerator = other.numerator - (x * other.denominator);
	return other;
}

/*****************
 *MULTIPLICATION *
 *****************/
Fraction operator*(int x, Fraction& other)
{
	Fraction tmp(x);
	tmp.denominator = tmp.denominator * other.denominator;
	tmp.numerator = tmp.numerator * other.numerator;
	return tmp;
}

Fraction operator*(Fraction& other, int x)
{
	Fraction tmp(x);
	tmp.denominator = tmp.denominator * other.denominator;
	tmp.numerator = tmp.numerator * other.numerator;
	return tmp;
}

Fraction operator*=(int x, Fraction& other)
{
	other.numerator *= x;
	other.denominator *= 1;
	return other;
}

Fraction operator*=(Fraction& other, int x)
{
	other.numerator *= x;
	other.denominator *= 1;
	return other;
}

/***********
 *DIVISION *
 ***********/
Fraction operator/(int x, Fraction& other)
{
	Fraction tmp;
	tmp.denominator = 1*other.numerator ;
	tmp.numerator = x*other.denominator;
	return tmp;
}

Fraction operator/(Fraction& other, int x)
{
	Fraction tmp(x);
	tmp.numerator = tmp.denominator * other.numerator;
	tmp.denominator = x * other.denominator;
	return tmp;
}

Fraction operator/=(int x, Fraction& other)
{
	other.numerator = other.numerator * 1;
	other.denominator = x * other.denominator;
	return other;
}

Fraction operator/=(Fraction& other, int x)
{
	other.numerator = other.numerator * 1;
	other.denominator = x * other.denominator;
	return other;
}
