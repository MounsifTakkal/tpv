#include "parser.h"
#include <QXmlStreamReader>
#include "qfile.h"

Parser::Parser(){

}

QStringList Parser::myParser()
{



        QFile xmlFile ("F:/Qt/Projectes/tpv/config.xml");



        QStringList settingsValues;



        if (!xmlFile.open(QIODevice::ReadOnly)) {

            return settingsValues;

        }



        QXmlStreamReader xmlReader;

        xmlReader.setDevice(&xmlFile);



        xmlReader.readNext();

        //Reading from the file

        while (!xmlReader.isEndDocument())

        {



            QString name = xmlReader.name().toString();



            if (name == "dbhost" )

            {

                settingsValues.append(xmlReader.readElementText());

            }

            if (name == "bbdd" )

            {

                settingsValues.append(xmlReader.readElementText());

            }

            if (name == "user" )

            {

                settingsValues.append(xmlReader.readElementText());

            }

            if (name == "pswd" )

            {

                settingsValues.append(xmlReader.readElementText());

            }


            xmlReader.readNext();

        }



        //close reader and flush file

        xmlReader.clear();

        xmlFile.close();



        return settingsValues;


}
