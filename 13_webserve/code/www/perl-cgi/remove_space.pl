#!/usr/bin/perl

use CGI qw(:standard);

print "Content-Type: text/html\r\n\r\n";
print "<!DOCTYPE html>";
print "<html>";
print "<head>";
print "<title>Remove Spaces</title>";
print "</head>";
print "<body>";

if (param()) {
    my $data = param('data');
    my $dataWithoutSpaces = $data;
    $dataWithoutSpaces =~ s/\s+//g;

    print "<h1>Remove Spaces from Data</h1>";
    print "<p>Data without Spaces: $dataWithoutSpaces</p>";
} else {
    print "<h1>Remove Spaces from Data</h1>";
    print "<p>Enter data in the form above and click 'Remove Spaces' to process.</p>";
}

print "</body>";
print "</html>";