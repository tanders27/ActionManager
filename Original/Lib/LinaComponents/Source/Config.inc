//////////////////////////////////////
///  Lina Configuration File       ///
///  ****************************  ///
///  (c) 2018 Dennis G�hlert a.o.  ///
//////////////////////////////////////

{$DEFINE LINA}
{ Bedingte Compilerversions-Ausdr�cke }
{$DEFINE VER_UNKNOWN}
{$IFDEF CONDITIONALEXPRESSIONS}
  {$IF Defined(VER320)}
    {$DEFINE VER_10_2}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER310) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_10_1_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER300) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_10_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER290) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE8_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER280) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE7_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER270) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE6_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER260) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE5_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER250) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE4_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER240) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE3_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER230) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE2_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER220) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_XE_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER210) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_2010_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER200) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_2009_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER185) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_2007_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER180) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_2006_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER170) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_2005_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
  {$IF Defined(VER150) OR (NOT Defined(VER_UNKNOWN))}
    {$DEFINE VER_7_UP}
    {$UNDEF VER_UNKNOWN}
  {$ENDIF}
{$ENDIF}
{ Globale Einstellungen }
{$DEFINE ADD_SPLASHENTRY}
{$DEFINE ADD_ABOUTENTRY}
{$DEFINE ADD_COMPONENTREG}
//{$DEFINE ADD_DEPENDENCIES}
{$DEFINE ADD_SINGLECATEGORY}
{$DEFINE WARN_INCOMPATIBLEPLATFORM}
{$DEFINE WARN_INCOMPATIBLECOMPILER}
{$DEFINE WARN_INCOMPATIBLEVERSION}
{ Globale Einschr�nkungen }
{$IFDEF CONDITIONALEXPRESSIONS}
  {$IF NOT Defined(VER_XE2_UP)}
    { Unter fr�heren Delphi-Versionen als XE2 stand lediglich eine Ziel-Platform
      f�r kompilierte Anwendungen zur Verf�gung. Deshalb brauchte noch nicht auf
      Kompatibilit�t zu mehrfacher Platform-Unterst�tzung geachtet werden. }
    {$DEFINE NO_MULTIPLATFORM}
  {$IFEND}
  {$IF (NOT Defined(DCC)) AND Defined(WARN_INCOMPATIBLECOMPILER)}
    { Nur der Delphi-Compiler wird (offiziell) unterst�tzt. }
    {$MESSAGE ERROR 'Lina Components requires Delphi'}
  {$IFEND}
  {$IF (NOT Defined(NO_MULTIPLATFORM)) AND (NOT Defined(MSWINDOWS)) AND Defined(WARN_INCOMPATIBLECOMPILER)}
    { Nur Windows wird (offiziell) als Ziel-Platform unterst�tzt. }
    {$MESSAGE ERROR 'Lina Components requires Microsoft Windows'}
  {$IFEND}
  {$IF Defined(VER_UNKNOWN) AND Defined(WARN_INCOMPATIBLEVERSION)}
    { Fr�here Delphi-Versionen als Delphi 7 werden nicht (offiziell)
      unterst�tzt. }
    {$MESSAGE ERROR 'Lina Components requires Delphi 7 or higher'}
  {$IFEND}
  {$IF NOT Defined(VER_2005_UP)}
    { Unter fr�heren Delphi-Versionen als 2005 gab es noch nicht die
      M�glichkeit, Records mit methoden zu versehen. Die Implementierung von
      Prozeduren und/oder Funktionen war Klassen vorenthalten. }
    {$DEFINE NO_RECORDMETHODS}
  {$IFEND}
  {$IF NOT Defined(VER_2007_UP)}
    { Unter fr�heren Delphi-Versionen als 2007 gab es (offiziell) noch keine
      Unterst�tzung f�r Windows-Vista-spezifische funktionen wie die TaskDialog-
      Komponente oder einige Funktionen.
      Damit dies nicht zu Problemen f�hrt, geht der Compiler darauf mithilfe
      dieser Direktive ein. }
    {$DEFINE NO_VISTA}
  {$IFEND}
  {$IF NOT Defined(VER_2009_UP)}
    { Unter fr�heren Delphi-Versionen als 2009 war die Nutzung generischer
      Datentypen (Generics) nicht m�glich. Da es ohne diese nahezu unm�glich
      scheint, typisierte Objekte, wie zum Beispiel typisierte TObjectList's
      zu deklarieren, fallen diese Deklarationen unter fr�heren Delphi-Versionen
      weg. Dies kann eventuell zu kompatibilit�tsproblemen zwischen
      unterschiedlichen Nutzern dieser Komponenten f�hren, l�sst sich aber nicht
      vermeiden. }
    {$DEFINE NO_GENERIC}
    { Unter fr�heren Delphi-Versionen als 2009 entsprach der String-Typenalias
      dem AnsiString-Typen. Da es gegebenfalls bei manchen externen (zB. OS-
      Spezifischen) Klassen zu Kompatibilit�tsproblemen kommmen k�nnte, wird
      hier eine �berpr�fung der Unicode-Unterst�tzung durchgef�hrt.
      Zu beachten ist jedoch, dass Delphi 2009 und h�her AnsiStrings implizit
      in UnicodeStrings umwandelt und umgekehrt (sofern m�glich). }
    {$DEFINE NO_UNICODE}
	{ Unter fr�heren Delphi-Versionen als 2009 standen Namensr�ume noch nicht
	  zur verf�gung. Daher sind Unitnamen wie zB. "System.Win.Registry" nicht
	  verf�gbar. Allerdings m�ssen diese trotzdem in nicht-GUI-Anwendungen
	  verwendet werden, da dort keine Unit-Aliase f�r VCL/FMX voreingestellt
	  sind. }
	{$DEFINE NO_NAMESPACE}
  {$IFEND}
  {$IF NOT Defined(VER_2010_UP)}
    { Unter fr�heren Delphi-Versionen als 2010 gab es ein Problem mit dem
      "crHandPoint" cursor, sodass dieser nicht korrekt unter Windows Vista oder
      h�her dargestellt wurde, sondern stattdessen im alten Windows-Look.
      Bei �lteren Delphi-Versionen als 2010 steht deswegen eine Pseudo-
      Komponente zur Behebung dieses Problems zur Verf�gung. }
    {$DEFINE NO_HANDPOINT}
  {$IFEND}
{$ENDIF}
