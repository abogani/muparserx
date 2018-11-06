#include "mpParserMessageProvider.h"
#include <cassert>
#include "mpError.h"


MUP_NAMESPACE_START

  //-------------------------------------------------------------------------------------------------
  //
  // class ParserMessageProviderBase - Base class for message providers
  //
  //-------------------------------------------------------------------------------------------------

  ParserMessageProviderBase::ParserMessageProviderBase()
  {}

  //-----------------------------------------------------------------------------------------------
  ParserMessageProviderBase::~ParserMessageProviderBase()
  {}

  //-----------------------------------------------------------------------------------------------
  void ParserMessageProviderBase::Init()
  {
    for (int i=0; i<ecCOUNT; ++i)
    {
      if (!m_vErrMsg[i].length())
        throw std::runtime_error("Incomplete translation (at least one error code missing)");
    }
  }

  //---------------------------------------------------------------------------------------------
  string_type ParserMessageProviderBase::GetErrorMsg(EErrorCodes eError) const
  {
    int nError = (int)eError;
    return (nError<(int)m_vErrMsg.size()) ? m_vErrMsg[nError] : string_type();
  }

  //-----------------------------------------------------------------------------------------------
  //
  // class ParserMessageProviderEnglish - English Parser Messages (default)
  //
  //-----------------------------------------------------------------------------------------------

  ParserMessageProviderEnglish::ParserMessageProviderEnglish()
    :ParserMessageProviderBase()
  {
    m_vErrMsg = {
      "Undefined token \"$IDENT$\" found at position $POS$.",
      "Internal error.",
      "Unknown escape sequence.",
      "Invalid function, variable or constant name.",
      "Invalid pointer to callback function.",
      "Invalid pointer to variable.",
      "Unexpected operator \"$IDENT$\" found at position $POS$.",
      "Unexpected end of expression found at position $POS$.",
      "Unexpected comma found at position $POS$.",
      "Unexpected parenthesis \"$IDENT$\" found at position $POS$.",
      "Unexpected function \"$IDENT$\" found at position $POS$.",
      "Unexpected value \"$IDENT$\" found at position $POS$.",
      "Unexpected variable \"$IDENT$\" found at position $POS$.",
      "Unexpected string token found at position $POS$.",
      "The \"$IDENT$\" operator must be preceded by a closing bracket.",
      "Unexprected newline.",
      "Missing parenthesis.",
      "If-then-else operator is missing an else clause.",
      "Misplaced colon at position $POS$.",
      "Too many parameters passed to function \"$IDENT$\".",
      "Too few parameters passed to function \"$IDENT$\".",
      "Division by zero occurred.",
      "The value passed as argument to function/operator \"$IDENT$\" is not part of its domain.",
      "Name conflict.",
      "Invalid value for operator priority (must be greater or equal to zero).",
      "Binary operator identifier conflicts with a built in operator.",
      "Unterminated string starting at position $POS$.",
      "String function called with a non string type of argument.",
      "Numerical function called with a non value type of argument.",
      "Value \"$IDENT$\" is of type '$TYPE1$'. There is no implicit conversion to type '$TYPE2$'.",
      "Argument $ARG$ of function/operator \"$IDENT$\" is of type '$TYPE1$' whereas type '$TYPE2$' was expected.",
      "Index to \"$IDENT$\" must be a positive integer value. '$TYPE1$' is not an acceptable type.",
      "Parser error.",
      "Invalid argument type.",
      "Value type conversion from type '$TYPE1$' to '$TYPE2$' is not supported!",
      "Array size mismatch.",
      "Using the index operator on the scalar variable \"$IDENT$\" is not allowed.",
      "Unexpected \"[]\".",
      "Unexpected \"{}\".",
      "Index to variable \"$IDENT$\" is out of bounds.",
      "Index operator dimension error.",
      "Missing \"]\".",
      "Missing \"}\".",
      "Assignment operator \"$IDENT$\" can't be used in this context.",
      "Can't evaluate function/operator \"$IDENT$\": $HINT$",
      "Parameter $ARG$ of function \"$IDENT$\" is invalid.",
      "Invalid number of function arguments.",
      "Possible arithmetic overflow occurred in function/operator \"$IDENT$\".",
      "Matrix dimension error.",
      "Variable \"$IDENT$\" is already defined.",
      "Constant \"$IDENT$\" is already defined.",
      "Function/operator \"$IDENT$\" is already defined."
    };
  }

#if defined(_UNICODE)

  //-------------------------------------------------------------------------------------------------
  //
  // class ParserMessageProviderGerman - German translations of Parser Messages
  //
  //-------------------------------------------------------------------------------------------------

  ParserMessageProviderGerman::ParserMessageProviderGerman()
    :ParserMessageProviderBase()
  {
    m_vErrMsg = {
      "Unbekanntes Token \"$IDENT$\" an Position $POS$ gefunden.",
      "Interner Fehler.",
      "Unbekannte Escape-Sequenz.",
      "Ungültiger Funktions-, Variablen- oder Konstantenbezeichner.",
      "Ungültiger Zeiger auf eine Callback-Funktion.",
      "Ungültiger Variablenzeiger.",
      "Unerwarteter Operator \"$IDENT$\" an Position $POS$.",
      "Unerwartetes Formelende an Position $POS$.",
      "Unerwartetes Komma an Position $POS$.",
      "Unerwartete Klammer \"$IDENT$\" an Position $POS$ gefunden.",
      "Unerwartete Funktion \"$IDENT$\" an Position $POS$ gefunden.",
      "Unerwarteter Wert \"$IDENT$\" an Position $POS$ gefunden.",
      "Unerwartete Variable \"$IDENT$\" an Position $POS$ gefunden.",
      "Unerwarteter Text an Position $POS$ gefunden.",
      "Der Operator \"$IDENT$\" muss stets auf eine schließenden Klammer folgen.",
      "Unerwarteter Zeilenumbruch.",
      "Fehlende Klammer.",
      "\"If-then-else\" Operator ohne \"else\" Zweig verwendet.",
      "Komma an unerwarteter Position $POS$ gefunden.",
      "Der Funktion \"$IDENT$\" wurden zu viele Argumente übergeben.",
      "Der Funktion \"$IDENT$\" wurden nicht genug Argumente übergeben.",
      "Division durch Null.",
      "Der Parameter der Funktion \"$IDENT$\" hat einen Wert, der nicht Teil des Definitionsbereiches der Funktion ist.",
      "Namenskonflikt",
      "Ungültige Operatorpriorität (muss größer oder gleich Null sein).",
      "Die Überladung für diesen Binäroperator steht im Widerspruch zu intern vorhanden operatoren.",
      "Die Zeichenkette an Position $POS$ wird nicht beendet.",
      "Es wurde eine Zeichenkette als Funktionseingabewert erwartet.",
      "Numerische Funktionen können nicht mit nichtnumerischen Parametern aufgerufen werden.",
      "Der Wert \"$IDENT$\" ist vom Typ '$TYPE1$' und es gibt keine passende Typkonversion in den erwarteten Typ '$TYPE2$'.",
      "Das Argument $ARG$ der Funktion oder des Operators \"$IDENT$\" ist vom Typ '$TYPE1$', erwartet wurde Typ '$TYPE2$'.",
      "Der Index der Variable \"$IDENT$\" muss ein positiver Ganzzahlwert sein. Der übergebene Indexwert ist vom Typ '$TYPE1$'.",
      "Allgemeiner Parser Fehler.",
      "Ungültiger Funktionsargumenttyp.",
      "Umwandlungen vom Typ '$TYPE1$' in den Typ '$TYPE2$' werden nicht unterstützt!",
      "Feldgrößen stimmen nicht überein.",
      "Der Indexoperator kann nicht auf die Skalarvariable \"$IDENT$\" angewandt werden.",
      "Eckige Klammern sind an dieser Position nicht erlaubt.",
      "Geschweifte Klammern sind an dieser Position nicht erlaubt.",
      "Indexüberschreitung bei Variablenzugriff auf \"$IDENT$\".",
      "Die Operation kann nicht auf Felder angewandt werden, deren Größe unterschiedlich ist.",
      "Fehlendes \"]\".",
      "Fehlendes \"}\".",
      "Der Zuweisungsoperator \"$IDENT$\" kann in diesem Zusammenhang nicht verwendet werden.",
      "Die Funktion bzw. der Operator \"$IDENT$\" kann nicht berechnet werden: $HINT$",
      "Der Parameter $ARG$ der Funktion \"$IDENT$\" is ungültig.",
      "Unzulässige Zahl an Funktionsparametern.",
      "Ein arithmetische Überlauf wurde in Funktion/Operator \"$IDENT$\" entdeckt.",
      "Matrixdimensionen stimmen nicht überein, Operation \"$IDENT$\" kann nicht ausgeführt werden.",
      "Die Variable \"$IDENT$\" is bereits definiert.",
      "Die Konstante \"$IDENT$\" is bereits definiert.",
      "Ein Element mit der Bezeichnung \"$IDENT$\" ist bereits definiert."
    };
  }

#endif // _UNICODE

MUP_NAMESPACE_END
