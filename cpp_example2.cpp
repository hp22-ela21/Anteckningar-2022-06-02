/***********************************************************************************
* C++ exempel 2 - Inmatning, utskrift och lagring av flyttal.
* 
* Kompilera i Linux och skapa en körbar fil döpt cpp_example2 via följande kommando:
* g++ *cpp -o cpp_example2 -Wall
* 
* Kör sedan programmet via följande kommando:
* ./cpp_example2
***********************************************************************************/

/* Inkluderingsdirektiv: */
#include <iostream>
#include <string>
#include <vector>

/***********************************************************************************
* readline: Läser in en rad med text från tangentbordet och lagrar i en sträng.
***********************************************************************************/
static void readline(std::string& s)
{
   std::getline(std::cin, s);
   std::cout << "\n";
   return;
}

/***********************************************************************************
* get_double: Returnerar ett flyttal inläst från tangentbordet. Decimaltecknet
*             kan matas in både med punkt och kommatecken.
***********************************************************************************/
static double get_double(void)
{
   while (true)
   {
      std::string s;
      readline(s);
      for (auto& i : s)
         if (i == ',') i = '.';
      try
      {
         return stod(s);
      }
      catch (std::invalid_argument&)
      {
         std::cerr << "Invalid argument, try again!\n\n";
      }
   }
}

/***********************************************************************************
* vector_print: Skriver ut innehållet ur en vektor av given datatyp via en specifik 
*               utenhet, där std::cout används som default för utskrift i konsolen.
***********************************************************************************/
template<class T>
static void vector_print(const std::vector<T>& v, std::ostream& stream = std::cout)
{
   stream << "----------------------------------------------------------------------\n";
   for (auto& i : v)
      stream << i << "\n";
   stream << "----------------------------------------------------------------------\n\n";
   return;
}

/***********************************************************************************
* vector_sum: Returnerar sum av samtliga element i en vektor av valbar
*             datatyp. Om vektorn är tom returneras 0. 
***********************************************************************************/
template<class T>
static T vector_sum(const std::vector<T>& v)
{
   if (!v.size()) return (T)0;
   T sum = (T)0;
   for (auto& i : v)
      sum += i;
   return sum;
}

/***********************************************************************************
* vector_average: Returnerar genomsnittet av samtliga element i en vektor av valbar
*                 datatyp. Om vektorn är tom returneras 0. Annars beräknas 
*                 genomsnittet som summan av alla element dividerat på antalet 
*                 befintliga element.
***********************************************************************************/
template<class T>
static double vector_average(const std::vector<T>& v)
{
   if (!v.size()) return 0.0;
   return static_cast<double>(vector_sum(v)) / v.size();
}

/***********************************************************************************
* main: Låter användaren mata in tio flyttal från konsolen och lagrar i en vektor.
*       Innehållet skrivs sedan ut i konsolen, tillsammans med summan samt 
*       genomsnittet av samtliga värden.
***********************************************************************************/
int main(void)
{
   std::vector<double> v1;

   std::cout << "Assigning ten floating point numbers to vector by input!\n\n";

   for (auto i = 0; i < 10; ++i)
   {
      std::cout << "Enter floating point number " << i + 1 << ":\n";
      v1.push_back(get_double());
   }

   vector_print(v1);
   std::cout << "Number of stored elements: " << v1.size() << "\n";
   std::cout << "Sum of all elements: " << vector_sum(v1) << "\n";
   std::cout << "Average of all elements: " << vector_average(v1) << "\n";
   return 0;
}