#ifndef WHEEL_H_
#define WHEEL_H_

#include <string>

using std::string;

/*
 *  destructor, copy constructor en assignment operator overloading is not needed as
 *  this class does not contain allocated memory
*/

class Wheel
{
  private:
    int diameter;
    string material;

  public:
    Wheel(int diameter, const string& material);
    /* pre : d > 0
       post: A Wheel object is created with the given material and diameter
    */

    string getMaterial() const;
    /* pre : -
       post: getMaterial()= <Wheel>'s material
    */

    void setMaterial(const string& material);
    /* pre : -
       post: <Wheel>'s material is now material
    */

    int getDiameter() const;
    /* pre : -
       post getDiameter() = <Wheel>'s diameter
    */

	Wheel(const Wheel& myWheel);
};

#endif
