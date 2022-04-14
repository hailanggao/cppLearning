#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
class Date {
   public:
    Date();
    Date(unsigned day, unsigned month, unsigned year);
    Date(const Date& other);
    unsigned GetDay() const;
    void SetDay(unsigned day);

    /**
     * Retrieves the month of class Get the month.
     * @return unsigned
     **/
    unsigned GetMonth() const;

    /**
     * Set the month.
     * @return void
     */
    void SetMonth(unsigned month);

    /**
     * Get the year.
     * @return unsigned
     */
    unsigned GetYear() const;

    /**
     * Set the number of year.
     * @return void
     */
    void SetYear(unsigned year);

    /**
     * Print date output
     * @return string
     */
    std::string ToString();

   private:
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
    std::string ConvertMonthToString();
};
#endif
