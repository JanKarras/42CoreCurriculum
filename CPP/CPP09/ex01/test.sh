#!/bin/bash

# Setze den Pfad zu deinem Programm, z.B. ./RPN
PROGRAM="./RPN"

# Funktion zum Testen eines einzelnen Ausdrucks
test_rpn() {
    input="$1"
    expected_output="$2"

    # Führe das RPN-Programm aus und speichere die Ausgabe
    output=$($PROGRAM "$input")  # Übergibt den Eingabeausdruck direkt als Argument

    # Vergleiche die Ausgabe mit dem erwarteten Ergebnis
    if [ "$output" == "$expected_output" ]; then
        echo "Test erfolgreich: '$input' -> $output"
    else
        echo "Test fehlgeschlagen: '$input' -> $output (Erwartet: $expected_output)"
    fi
}

# Führe Tests durch
test_rpn "3 4 +" "7"
test_rpn "2 5 *" "10"
test_rpn "3 4 + 5 *" "35"
test_rpn "6 2 /" "3"
test_rpn "3 0 /" "Division by zero"
test_rpn "10 4 -" "6"
test_rpn "3 4 + 2 * 5 +" "19"
test_rpn "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
test_rpn "7 7 * 7 -" "42"
test_rpn "1 2 * 2 / 2 * 2 4 - +" "0"
test_rpn "1 2 * 2 / 2 * 2 4.5 - +" "-0.5"
test_rpn "(1 + 1)" "Error"

# Weitere Tests könnten hinzugefügt werden
