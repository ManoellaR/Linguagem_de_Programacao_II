#include "GenericElement.hpp" 
#include "Shapes.hpp"
#include <vector>

vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main(){
    vector< GenericElement* > myListOfElements;

    if(NDEBUG) cout << "Enter with a shape configuration file to load:" << endl;
    string path;
    cin >> path;

    ifstream filereader(path);
    
    if(!filereader.is_open())
        return 1;
    
    string tmp;
    while(getline(filereader, tmp)){
        if(tmp == "circle"){
            getline(filereader, tmp);
            Circle circulo(atof(tmp.c_str()));
            myListOfElements.push_back(new GenericElement(circulo));
        }

        if(tmp == "square"){
            getline(filereader, tmp);
            Square quadrado(atof(tmp.c_str()));
            myListOfElements.push_back(new GenericElement(quadrado));
        }

        if(tmp == "triangle"){
            getline(filereader, tmp);
            size_t found = tmp.find(',');
            if(found != std::string::npos){
                vector < string > pointA = split(tmp, ',');
                Point2d p1(atof(pointA[0].c_str()), atof(pointA[1].c_str()));
                getline(filereader, tmp);
                vector < string > pointB = split(tmp, ',');
                Point2d p2(atof(pointB[0].c_str()), atof(pointB[1].c_str()));
                getline(filereader, tmp);
                vector < string > pointC = split(tmp, ',');
                Point2d p3(atof(pointC[0].c_str()), atof(pointC[1].c_str()));

                Triangle triangulo(p1, p2, p3);
                myListOfElements.push_back(new GenericElement(triangulo));
            }
            else{
                float edge1 = atof(tmp.c_str());
                getline(filereader, tmp);
                float edge2 = atof(tmp.c_str());
                getline(filereader, tmp);
                float edge3 = atof(tmp.c_str());

                Triangle triangulo(edge1, edge2, edge3);
                myListOfElements.push_back(new GenericElement(triangulo));
            }
        }

        if(tmp == "sphere"){
            getline(filereader, tmp);
            Sphere esfera(atof(tmp.c_str()));
            myListOfElements.push_back(new GenericElement(esfera));
        }

        if(tmp == "tetrahedron"){
            getline(filereader, tmp);
            vector < string > pointA = split(tmp, ',');
            Point3d p1(atof(pointA[0].c_str()), atof(pointA[1].c_str()), atof(pointA[2].c_str()));
            getline(filereader, tmp);
            vector < string > pointB = split(tmp, ',');
            Point3d p2(atof(pointB[0].c_str()), atof(pointB[1].c_str()), atof(pointB[2].c_str()));
            getline(filereader, tmp);
            vector < string > pointC = split(tmp, ',');
            Point3d p3(atof(pointC[0].c_str()), atof(pointC[1].c_str()), atof(pointC[2].c_str()));
            getline(filereader, tmp);
            vector < string > pointD = split(tmp, ',');
            Point3d p4(atof(pointD[0].c_str()), atof(pointD[1].c_str()), atof(pointD[2].c_str()));

            Tetrahedron tetraedro(p1, p2, p3, p4);
            myListOfElements.push_back(new GenericElement(tetraedro));
        }

        if(tmp == "cube"){
            getline(filereader, tmp);
            Cube cubo(atof(tmp.c_str()));
            myListOfElements.push_back(new GenericElement(cubo));
        }
    }

    filereader.close();

    for(size_t i=0; i< myListOfElements.size(); i++)
    {   
        cout << "Object #" << i << " is " << myListOfElements.at(i)->ShowInfo() << endl;
        delete myListOfElements.at(i);
    }
    
    return 0;
}
