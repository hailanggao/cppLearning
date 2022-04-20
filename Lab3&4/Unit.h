
// author KRI
// modified smr

#ifndef UNIT_H
#define UNIT_H
#include <iostream>

/**
 * @class UNIT
 * unit has id, name, and credits
 * @author Gordon
 * @version 01
 * @date 31/03/2022
 */
const unsigned UnitIdSize = 10;
const unsigned UnitNameSize = 255;

class Unit {
public:
    /**
     * Default constructors of Unit Class
     */
    Unit();

    /**
     * Construct a unit from a name, id,
     * and number of credits.
     */
    Unit(std::string& id, std::string& nam, unsigned cred);

    /**
     * Copy constructor
     */
    Unit(const Unit& other);

    /**
     * Get the name of unit class.
     * @return string
     */
    std::string GetUnitName() const;

    /**
     * Set the name of unit.
     * @return void
     */
    void SetUnitName(std::string& name);

    /**
     * Get the unit id.
     * @return unsigned
     */
    std::string GetUnitId() const;

    /**
     * Set the unit id of credits.
     * @return void
     */
    void SetUnitId(std::string& id);

    /**
     * Get the number of credits.
     * @return unsigned
     */
    unsigned GetCredits() const;

    /**
     * Set the number of credits.
     * @return void
     */
    void SetCredits(unsigned cred);

    /**
     * Print Unit output
     * @return string
     */
    std::string ToString();

    /**
     * Friend Function to overload operator <<
     * @return ostream
     */
    friend std::ostream& operator << (std::ostream& os, Unit& U);

private:
    std::string unitId; //unit id
    std::string unitName; //unit name
    int credits; //unit credits
};
#endif
