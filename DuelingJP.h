// Created by Andrew Asplund
// Date: 02/07/2023
// Revision: 1.0

#ifndef INC_5011_P2_DUELINGJP_H
#define INC_5011_P2_DUELINGJP_H

#include "JumpPrime.h"


/*
 * The DuelingJP encapsulates a series of JumpPrime objects, specified when
 * the user instantiates the DuelingJP object. The primary purpose of the
 * DuelingJP object is to count collisions and inversions. A collision occurs
 * when two JumpPrime objects return the same result on an up() call or, in the
 * alternative, a down() call. An inversion occurs when two JumpPrime objects
 * return the same result on alternate calls (i.e., one up(), the other down()).
 *
 * METHODS:
 * 1. The constructor accepts an array of integers representing the number
 * to be encapsulated by each JumpPrime object and an integer representing
 * the number of items in the array. Once a DuelingJP object is instanced,
 * the size and value of the JumpPrime objects cannot be changed by the user.
 * 2. countCollisions is used to count the number of collisions across all of
 * the JumpPrime objects stored in the DuelingJP object. This can be done
 * either in the up() direction or the down() direction.
 * 3. countInversions is used to count the number of inversions across all of
 * the JumpPrime objects stored in the DuelingJP object.This results in two
 * activations of each JumpPrime object in the DuelingJP object (once in the
 * up() direction and once in the down() direction).
 *
 * ASSUMPTIONS:
 * 1. When counting collisions, a single JumpPrime object returning a specific
 * value on its own is considered NO COLLISION. Any additional JumpPrime object
 * that returns the same value is considered an added collision. For example,
 * if three JumpPrime objects return the same number on an up() call, then
 * DuelingJP will count TWO (2) COLLISIONS.
 * 2. When counting inversions, unique instances in which the up() result from
 * a JumpPrime object equals the down() result of another JumpPrime object
 * is counted.
 * 3. Anytime the object attempts to count collisions or inversions and an
 * associated JumpPrime has deactivated, the associated method reactivates the
 * object.
 * 4. During the counting of inversions, it is possible for a JumpPrime
 * to jump in between the up(0 and down() call. This is understood and
 * no exceptions are made for it.
 * 5. A DuelingJP can be added to another DuelingJP object. This yields
 * a DuelingJP object which has JumpPrime objects that have encapsulated
 * numbers that duplicate the encapsulated numbers of the JumpPrime objects
 * in the DuelingJP objects.
 * 6. A JumpPrime object can be added to a DuelingJP object. This increases
 * the size of the DuelingJP by one, adding a new JumpPrime object at the end
 * of the DuelingJP object.
 */

/// DuelingJP is a container for JumpPrime objects used for testing.
class DuelingJP {

    /// Pointer to array of JumpPrime objects of size listSize.
    JumpPrime *jumperList;

    /// The size of the jumperList array.
    int listSize;

    /// areActive verifies that all JumpPrime objects are currently active
    /// (i.e., they have not been deactivated).
    /// @return true if all of the member JumpPrime objects are active.
    /// @deprecated
    bool areActive();

    /// reactivateJumpers goes through all of the JumpPrime objects and
    /// reactivates any that were not active.
    /// @deprecated
    void reactivateJumpers();

    /// testJumper verifies that a specified JumpPrime object is active and
    /// ready for testing. If not, it revives the object.
    /// @param jumperNumber the position in the jumperList to test
    /// @return true if the JumpPrime object in position jumperNumber is
    /// active and ready for use
    bool testJumper(int jumperNumber);

public:

    /// DuelingJP Constructor creates a new DuelingJP object with a set of
    /// JumpPrime objects specified by a given array of initial values.
    /// @param [in] initValues Array of initial values for JumpPrime objects
    /// @param [in] size The size of the array of initial values.
    /// @pre All values of array are valid JumpPrime initial values.
    DuelingJP(const int *initValues, int size);

    /// DuelingJP Destructor for disposing of JumpPrime garbage
    ~DuelingJP();

    /// DuelingJP Copy Constructor creates a duplicate DuelingJP object with
    /// the same JumpPrime objects.
    /// @param [in] sourceObject The DuelingJP object to copy.
    DuelingJP(DuelingJP &sourceObject);


    /// DuelingJP Move Constructor assigns a new DuelingJP with the content
    /// of the original and eliminates the source.
    /// @param [in] sourceObject The DuelingJP object to move
    DuelingJP(DuelingJP && sourceObject);


    /// DuelingJP overloaded assignment operator assigns a duplicate of the
    /// contents of one DuelingJP object to another.
    /// @param [in] sourceObject  The DuelingJP object to copy.
    /// @return A pointer to the new DuelingJP object.
    DuelingJP &operator=(const DuelingJP & sourceObject);

    /// DuelingJP overloaded move assignment operator swaps the contents
    /// of one DuelingJP to another.
    /// @param sourceObject
    /// @return A pointer to the DuelingJP object with the content.
    DuelingJP &operator=(DuelingJP && sourceObject);

    /**
     * Compares two DuelingJP objects. Two DuelingJP objects are considered
     * equal if they have the same number of JumpPrime elements and the
     * ordered elements all have the same encapsulated value.
     * @param compareObject the DuelingJP to compare to.
     * @return true if equal, false otherwise.
     */
    bool operator==(const DuelingJP& compareObject) const;

    /**
     * Compares two DuelingJP objects. Two DuelingJP objects are considered
     * equal if they have the same number of JumpPrime elements.
     * @param compareObject the DuelingJP to compare to.
     * @return true if not equal, false otherwise.
     */
    bool operator!=(const DuelingJP& compareObject) const;

    /**
     * Compares two DuelingJP objects. A DuelingJP object is considered
     * greater than another if it has a greater number of JumpPrime elements.
     * @param compareObject the object to compare
     * @return true if the LHS is greater in size, false otherwise
     */
    bool operator>(const DuelingJP& compareObject) const;

    /**
     * Compares two DuelingJP objects. A DuelingJP object is considered
     * greater than or equal to another if it has a greater than or equal
     * number of JumpPrime elements.
     * @param compareObject the object to compare
     * @return true if the LHS is greater than or equal in size, false otherwise
     */
    bool operator>=(const DuelingJP& compareObject) const;

    /**
     * Compares two DuelingJP objects. A DuelingJP object is considered
     * lesser than another if it has a lesser number of JumpPrime elements.
     * @param compareObject the object to compare
     * @return true if the LHS is lesser in size, false otherwise
     */
    bool operator<(const DuelingJP& compareObject) const;

    /**
     * Compares two DuelingJP objects. A DuelingJP object is considered
     * less than or equal to another if it has a less than or equal
     * number of JumpPrime elements.
     * @param compareObject the object to compare
     * @return true if the LHS is less than or equal in size, false otherwise
     */
    bool operator<=(const DuelingJP& compareObject) const;

    /**
     * Adds the contents of two DuelingJP objects together. The resulting
     * DuelingJP object will contain an array of JumpPrime objects that
     * encapsulate the same number as the originating DuelingJP objects.
     * @param addObject the DuelingJP to add to the operand.
     * @return a new DuelingJP object with a list of JumpPrime objects made
     * from the encapsulated numbers of the component DuelingJP objects.
     */
    DuelingJP operator+(const DuelingJP& addObject) const;

    /**
     * Adds a JumpPrime object to the contents of a DuelingJP object. This
     * yields a new DuelingJP object with a size increased by one.
     * @param addJP the JumpPrime object to add to the DuelingJP object.
     * @return a new DuelingJP object with a list of JumpPrime objects made
     * from the encapsulated numbers of the component DuelingJP object and
     * the JumpPrime object.
     */
    DuelingJP operator+(const JumpPrime& addJP) const;

    /**
     * Add the contents of a DuelingJP object to the existing object.
     * The resulting DuelingJP object will contain the previously encapsulated
     * JumpPrime objects along with copies of the JumpPrime objects in the
     * operand DuelingJP object.
     * @param addObject the DuelingJP object to add
     * @return a reference to the LHS DuelingJP object
     */
    DuelingJP operator+=(const DuelingJP& addObject);



    /// countCollisions will run a single pass test through the list of
    /// JumpPrime objects, identifying any instances where two objects have
    /// the same value.
    /// @param [in] testUp If true, tests the JumpPrime objects in the "up"
    /// direction. Defaults to true.
    /// @return The number of JumpPrime objects that collided.
    int countCollisions(bool testUp = true);

    /// countInversions will go through both the up() and down() methods of
    /// every JumpPrime object in the DuelingJP object and count the number
    /// of unique times an up() result equals a down() result.
    /// @return The number of JumpPrime object inversions.
    int countInversions();


    /// getSize returns the number of JumpPrime objects in this DuelingJP.
    /// @return The number of JumpPrime objects in the DuelingJP object.
    int getSize() const;



};


#endif //INC_5011_P2_DUELINGJP_H
