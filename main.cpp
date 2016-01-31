/*
Copyright 2015  Ian Knight <ian@knightly.xyz>

This file is part of atem-cli.

atem-cli is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with atem-cli.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QtCore>
#include <QApplication>
#include <QTextStream>
#include <iostream>

#include "qatemconnection.h"
#include "qatemmixeffect.h"
#include "cliapp.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream qout(stdout);

    if (argc!=2){
        qout << "Usage: atemcli [ip-address]" << endl;
        exit(0);
    }
    
    QString addr(argv[1]);
    
    CLIApp *app = new CLIApp(&a,addr);
    QObject::connect(app, SIGNAL(finished()), &a, SLOT(quit()));
    QTimer::singleShot(0, app, SLOT(run()));

    return a.exec();

}

