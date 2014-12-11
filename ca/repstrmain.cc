#include "repstring.h"
#include <iostream>
#include "repstring.h"
#include <algorithm>

const int max = 1000;

int main()
{
  int yourMark = 1;
  /* 2-es */
  basic_repeating_string<char> a;
  a.repeating_string_push_back( 'b' );
  a.repeating_string_push_back( 'l' );
  a.repeating_string_push_back( 'a' );
  a.set_repeating( 2 );

  const basic_repeating_string<char> ca = a;
  a.set_repeating( 3 );
  a.repeating_string_push_back( 'h' );

  a.print();
  std::endl( std::cout );
  ca.print();
  std::endl( std::cout );

  basic_repeating_string<wchar_t> w;
  w.repeating_string_push_back( L'a' );
  w.repeating_string_push_back( L'b' );

  basic_repeating_string<char> t;
  for( int i = 0; i < max; ++i )
  {
    t.repeating_string_push_back( 'A' );
    t.repeating_string_push_back( 'B' );
  }
  t.set_repeating( 2 );

  if ( 6 == ca.size() && 12 == a.size() && max * 4 == t.size() &&
       1 == ca.find( "lab" ) && 3 == a.find( "hbla" ) &&
       -1 == t.find( "BBB" ) && -1 == w.find( L"AB" ) )
  {
    yourMark = w.size();
  }

  /* 3-as */
  a[3] = 'a';
  if ( 'l' == ca[4] && a[7] == ca[2] && L'a' == w[0] &&
       0 < ca.compare( "bab" ) &&
       0 == w.compare( L"ab" ) &&
       0 > t.compare( "C++" ) )
  {
    yourMark = a.find( "ab" );
  }

  /* 4-es */
  basic_repeating_string<char>::iterator i =
    std::find( a.begin(), a.end(), 'a' );
  basic_repeating_string<wchar_t>::iterator wi =
    std::find( w.begin(), w.end(), 's' );
  basic_repeating_string<char>::iterator j =
    std::find( t.begin(), t.end(), 'B' );
  basic_repeating_string<char>::iterator k =
    std::find( a.begin(), a.end(), 'l' );

  if ( i != a.end() && wi == w.end() && j != t.end() && k != a.end() )
  {
    yourMark = ( i - a.begin() ) + ( j - t.begin() ) +  ( k - a.begin() );
  }

  /* 5-os */
  basic_repeating_string<char> is;
  is.set_repeating( 3 );
  is.repeating_string_push_back( 'a' );
  is.repeating_string_push_back( 'b' );
  is.repeating_string_push_back( 'c' );
  is[ 1 ] = 'd';
  *(is.begin() ) = 'e' ;
  if ( 0 == std::count( is.begin(), is.end(), 'a' ) &&
       0 == std::count( is.begin(), is.end(), 'b' ) &&
       3 == std::count( is.begin(), is.end(), 'c' ) )
  {
    yourMark = std::count( a.begin(),  a.end(),   'b' ) +
               std::count( is.begin(), is.end(),  'c' ) -
               std::count( w.begin(),  w.end(),  L'a' );
  }

  std::cout << "Your mark is " << yourMark;
  std::endl( std::cout );
}
