
// UNIT.H - Unit class definition

#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include <string>  // C++ string library

#include "date.h"
#include "unit.h"
using namespace std;

/**
 * @class Result
 * Manages Unit Result marks
 * @author Laura
 * @version 01
 * @date 31/03/22
 */
class Result {
   public:
    /**
     * Declaration of a default constructor inside of class definition.
     */
    Result();

    /**
     * Construct a Result from a unit class and marks
     */
    Result(Unit& unit, float marks, Date& date);

    /**
     * Copy constructor
     */
    Result(const Result& other);

    /**
     * Get the unit.
     * @return float
     */
    Unit GetUnit();

    /**
     * Set the unit.
     * @return void
     */
    void SetUnit(Unit& unit);

    /**
     * Get the value of marks.
     * @return float
     */
    float GetMarks() const;

    /**
     * Set the value of marks.
     * @return void
     */
    void SetMarks(float marks);

    /**
     * Get the date.
     * @return Date
     */
    Date GetDate() const;

    /**
     * Set the date.
     * @return void
     */
    void SetDate(Date& date);

    /**
     * Get the value of credit.
     * @return unsigned
     */
    unsigned GetCredits() const;

    /**
     * Print Result output
     * @return string
     */
    string ToString();

   private:
    Unit m_unit;
    float m_marks;
    Date m_date;
    string RoundMarksToOneDecPl(); //Convert m_marks to 1 decimal place string
};
#endif
