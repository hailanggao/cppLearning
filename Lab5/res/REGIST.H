// REGIST.H - Registration class definition

#ifndef REGIST_H
#define REGIST_H

#include <iostream>
#include "result.h"
#include "Vector.h"
const unsigned MaxResults = 10;

/**
 * @class Registration
 * register student detail with student ID,
 * number of result, array of result name and semester.
 * @author Laura
 * @version 01
 * @date 31/02/22
 */
class Registration {
   public:
    /**
     * Default constructors of Registration Class
     */
    Registration();

    /**
     * Construct a Registration class from a student id, semester, and count
     */
    Registration(long id, unsigned sem, unsigned co);

    /**
     * Copy constructor
     */
    Registration(const Registration& other);

    /**
     * Get the student id.
     * @return unsigned
     */
    long GetStudentId() const;

    /**
     * Set the student id of registration.
     * @return void
     */
    void SetStudentId(long id);

    /**
     * Get the unit id.
     * @return unsigned
     */
    unsigned GetSemester() const;

    /**
     * Set the unit id of credits.
     * @return void
     */
    void SetSemester(unsigned sem);

    /**
     * Total Credits that the student earned.
     * @return unsigned
     */
    unsigned GetCredits() const;

    /**
     * Get number of unit student taking.
     * @return unsigned
     */
    unsigned GetCount() const;

    /**
     * Set number of unit the student is taking
     * @return unsigned
     */
    void SetCount(unsigned co);

    /**
     * Add result to result array
     * @return unsigned
     */
    void AddResult(Result& result, unsigned index);

    /**
     * Print Registration output
     * @return string
     */
    string ToString();

    /**
     * Friend Function to overload operator >>
     * @return istream
     */
    friend istream& operator >> (istream& input, Registration& R);

    /**
     * @brief Friend Function to overload operator <<
     * @return ostream
     */
    friend ostream& operator << (ostream& os, Registration& R);

   private:
    long studentId;
    unsigned semester;
    unsigned count;
    Vector<Result> results;
};
#endif
