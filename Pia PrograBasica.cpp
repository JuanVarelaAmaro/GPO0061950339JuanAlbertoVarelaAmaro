#include<iostream>
#include<conio.h>
#include<string.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<locale.h>
#include<windows.h>

using namespace std;

int* NumArt, * Fecha, registros, n = 1;
string* Nombre, * Clasi, * Carac, * Desc, * Genero;
float* PrecioU, * IVA, * Total;

void alta();
void modificar();
void eliminar();
void lista();
void archivo();

int main()
{
	setlocale(LC_ALL, "spanish");   //Pone el programa en español, permite el uso de la ñ.
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	int opcion;

	printf("\t ***Gamer's Stuff*** \n");
	printf("1.-Agregar Articulo \n2.-Modificar Articulo \n3.-Eliminar Articulo \n4.-Lista de Articulos \n5.-Limpiar pantalla \n6.-Salir \n");
	scanf_s("%d", &opcion);

	switch (opcion)
	{
	case 1: //Agregar registros de articulos
		alta();
		system("pause");
		return main();
		break;

	case 2: //Modificar Articulo
		modificar();
		system("pause");
		return main();
		break;

	case 3: //Eliminar Articulo
		eliminar();
		system("pause");
		return main();
		break;

	case 4:  // Lista de Articulos
		lista();
		system("pause");
		return main();
		break;

	case 5:   //Limpieza de Pantalla
		system("cls");
		return main();
		break;

	case 6:  //Salir y guardar registros en archivo formato .txt
		archivo();
		exit(1);
		system("pause");
		break;

	default:   //En caso de que el usuario ingrese una opcion que no este entre el 1 al 6
		printf("Ingresa una opcion valida\n");
		return main();
		break;
	}
}

void alta()
{
	printf("Ingrese la cantidad de registros que quiere dar de alta: \n");
	scanf_s("%d", &registros);
	if (registros > 0)
	{
		NumArt = new int[registros];
		Fecha = new int[registros];
		Nombre = new string[registros];
		Clasi = new string[registros];
		Carac = new string[registros];
		Genero = new string[registros];
		Desc = new string[registros];
		PrecioU = new float[registros];
		IVA = new float[registros];
		Total = new float[registros];

		for (int i = 0; i < registros; i++)
		{
			printf("Ingrese el numero del articulo: \n");
			scanf_s("%d", &NumArt[i]);
			do
			{
				if (NumArt[i] != NumArt[i - n])
				{
					n = n + 1;
				}
				else
				{
					printf("Este articulo ya existe \n");
					printf("Ingresa un nuevo numero de articulo: \n");
					scanf_s("%d", NumArt[i]);
				}
			} while (n < registros);
			printf("Año de lanzamiento: \n");
			scanf_s("%d", &Fecha[i]);
			printf("Nombre del videojuego: \n");
			cin.ignore();
			getline(cin, Nombre[i]);
			printf("Clasificacion del videojuego: \n");
			getline(cin, Clasi[i]);
			printf("Caracteristicas del videojuego: \n");
			getline(cin, Carac[i]);
			printf("Genero del videojuego: \n");
			getline(cin, Genero[i]);
			printf("Descripcion del videojuego: \n");
			getline(cin, Desc[i]);
			printf("Precio del videojuego: \n");
			scanf_s("%f", &PrecioU[i]);
			IVA[i] = PrecioU[i] * .16;
			Total[i] = PrecioU[i] + IVA[i];
			printf("---------------------------------------------------- \n\n");  //Separador para asi no confundir los datos 



			if (i == (registros - 1))
			{
				break;

			}
		}
	}
	else
	{
		printf("Ingresa una opcion valida\n");
	}
}

void modificar()
{
	int Artmod;

	printf("Ingresa el numero de articulo a modificar: \n");
	scanf_s("%d", &Artmod);
	if (Artmod > 0)
	{
		for (int i = 0; i < registros; i++)
		{
			if (Artmod == NumArt[i])
			{
				printf("Año de lanzamiento: \n");
				scanf_s("%d", &Fecha[i]);
				printf("Nombre del juego: \n");
				cin.ignore();
				getline(cin, Nombre[i]);
				printf("Clasificacion del juego: \n");
				getline(cin, Clasi[i]);
				printf("Caracteristicas del juego: \n");
				getline(cin, Carac[i]);
				printf("Genero del juego: \n");
				getline(cin, Genero[i]);
				printf("Descripcion del juego: \n");
				getline(cin, Desc[i]);
				printf("Precio del juego: \n");
				scanf_s("%f", &PrecioU[i]);
				IVA[i] = PrecioU[i] * .16;
				Total[i] = PrecioU[i] + IVA[i];
			}
		}
	}
	else
	{
		printf("Opcion invalida \n");
	}

}

void eliminar()
{
	int Artelm;
	printf("Ingrese el numero de articulo que desee eliminar: \n");
	scanf_s("%d", &Artelm);

	for (int i = 0; i < registros; i++)
	{
		if (Artelm == NumArt[i])
		{
			NumArt[i] = 0;
		}
	}

}

void lista()
{
	int opcion2 = 0;
	string busc;

	printf("Las opciones de busqueda son las siguientes: \n1.-Clasificacion \n2.-Genero \n3.-Ver todos \n4.-Salir \n");
	scanf_s("%d", &opcion2);

	switch (opcion2)
	{

	case 1:
		printf("Ingresa la clasificacion a buscar: \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (Clasi[i] == busc)
			{
				printf("Numero articulo: %d \n", NumArt[i]);
				printf("Año: %d \n", Fecha[i]);
				printf("Nombre: %s \n", Nombre[i].c_str());
				printf("Clasificacion: %s \n", Clasi[i].c_str());
				printf("Genero: %s \n", Genero[i].c_str());
				printf("Caracteristicas: %s \n", Carac[i].c_str());
				printf("Descripcion: %s \n", Desc[i].c_str());
				printf("Precio: %f \n", PrecioU[i]);
				printf("Iva: %f \n", IVA[i]);
				printf("Total: %f \n", Total[i]);
			}
		}
		break;

	case 2:
		printf("Ingresa el genero a buscar: \n");
		cin.ignore();
		getline(cin, busc);
		for (int i = 0; i < registros; i++)
		{
			if (Genero[i] == busc)
			{
				printf("Numero articulo: %d \n", NumArt[i]);
				printf("Año: %d \n ", Fecha[i]);
				printf("Nombre: %s \n", Nombre[i].c_str());
				printf("Clasificacion: %s \n", Clasi[i].c_str());
				printf("Genero: %s \n", Genero[i].c_str());
				printf("Caracteristicas: %s \n", Carac[i].c_str());
				printf("Descripcion: %s \n", Desc[i].c_str());
				printf("Precio: %f \n", PrecioU[i]);
				printf("Iva: %f \n", IVA[i]);
				printf("Total: %f \n", Total[i]);
			}
		}
		break;

	case 3:
		for (int i = 0; i < registros; i++)
		{
			if (NumArt[i] != 0)
			{
				printf("Numero articulo: %d \n", NumArt[i]);
				printf("Año: %d \n ", Fecha[i]);
				printf("Nombre: %s \n", Nombre[i].c_str());
				printf("Clasificacion: %s \n", Clasi[i].c_str());
				printf("Genero: %s \n", Genero[i].c_str());
				printf("Caracteristicas: %s \n", Carac[i].c_str());
				printf("Descripcion: %s \n", Desc[i].c_str());
				printf("Precio: %f \n", PrecioU[i]);
				printf("Iva: %f \n", IVA[i]);
				printf("Total: %f \n", Total[i]);
			}
		}

	case 4:
		break;

	default:
		printf("Ingresa una opcion valida \n");
		return lista();
		break;
	}
}

void archivo()
{
	ofstream archivo;
	string nombredelarchivo;

	nombredelarchivo = "Gamer's Stuff";
	archivo.open(nombredelarchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("ERROR NO SE GENERO EL ARCHIVO \n");
		system("pause");
		exit(1);
	}

	archivo << "\t\t INFORMACION \n";
	for (int i = 0; i < registros; i++)
	{
		if (NumArt[i] != 0)
		{
			archivo << "Registro " << i + 1 << endl;
			archivo << "Numero articulo: " << NumArt[i] << endl;
			archivo << "Año: " << Fecha[i] << endl;
			archivo << "Nombre: " << Nombre[i].c_str() << endl;
			archivo << "Clasificacion: " << Clasi[i].c_str() << endl;
			archivo << "Genero: " << Genero[i].c_str() << endl;
			archivo << "Caracteristicas: " << Carac[i].c_str() << endl;
			archivo << "Descripcion: " << Desc[i].c_str() << endl;
			archivo << "Precio: " << PrecioU[i] << endl;
			archivo << "Iva: " << IVA[i] << endl;
			archivo << "Total: " << Total[i] << endl;
		}
	}

	archivo.close();
}