#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>


using namespace std;

struct empresa
{
	//declaracion de variable

	int idcontrato, NumArt;
	string proveedor, NomVid, Clasi, Carac, Desc, Genero, Lanz;
	float subtotal, iva, total;
};


int main()
{
	empresa compras[3];
	int opcion, busqueda;

	do
	{
		printf("\t ***Gamer's Stuff *** \n");
		printf("1.-Agregar Articulo \n2-. Modificar articulo \n3-. Eliminar Articulo \n4-. Lista de articulos vigentes \n5-. Limpiar pantalla \n6-. Salir\n");
		scanf_s("%d", &opcion);

		switch (opcion)
		{
		case 1:
			//capturar y guardar los datos por posicion
			for (int i = 0; i < 3; i++)
			{
				compras[i].idcontrato = 20220000 + i;
				printf("ID CONTRATO: %d \n", compras[i].idcontrato);
				int salida = 1;

				do
				{
					printf("ingrese el Numero de Articulo \n");
					scanf_s("%d", &compras[i].NumArt);
				} while (compras[i].NumArt == compras[i - 1].NumArt || compras[i].NumArt == compras[i - 2].NumArt);


				//proveedor 
				printf("ingrese el proveedor \n");
				cin.ignore();
				getline(cin, compras[i].proveedor);
				printf("ingrese el nombre del videojuego \n");
				cin.ignore();
				getline(cin, compras[i].NomVid);
				printf("ingrese el ano de lanzamiento \n");
				cin.ignore();
				getline(cin, compras[i].Lanz);
				printf("ingrese la clasificacion del videojuego \n");
				cin.ignore();
				getline(cin, compras[i].Clasi);
				printf("ingrese las caracteristicas del juego \n");
				cin.ignore();
				getline(cin, compras[i].Carac);
				printf("ingrese una descripcion \n");
				cin.ignore();
				getline(cin, compras[i].Desc);
				printf("ingrese el genero \n");
				cin.ignore();
				getline(cin, compras[i].Genero);
				printf("ingrese el subtotal \n");
				scanf_s("%f", &compras[i].subtotal);
				compras[i].iva = compras[i].subtotal * .16;
				compras[i].total = compras[i].subtotal + compras[i].iva;
			}
			break;

		case 2:
			system("cls");
			cout << "Elegir artiuclo a modificar \n";
			system("pause");
			return main();

			break;


		case 3:// no hara nada
			printf("ingrese el Numero de Articulo");
			scanf_s("%d", &busqueda);

			//imprimir los datos por posicion 
			for (int i = 0; i < 3; i++)
			{
				if (busqueda == compras[i].NumArt)
				{
					compras[i].NumArt = 0;
				}
			}
			break;

		case 4:
			int opc2;
			printf("1.- Numero Articulo \n 2.-Listas Vigentes");
			scanf_s("%d", &opc2);
			if (opc2 == 1)
			{
				printf("ingrese el numero del articulo");
				scanf_s("%d", &busqueda);

				//imprimir los datos por posicion 
				for (int i = 0; i < 3; i++)
				{
					if (busqueda == compras[i].NumArt)
					{
						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("Nombre del Videojuego: %s\n", compras[i].NomVid.c_str());
						printf("num de articulo: %d \n", compras[i].NumArt);
						//proveedor
						printf("proveedor %s", compras[i].proveedor.c_str());
						printf("Ano de lanzamiento: %s\n", compras[i].Lanz.c_str());
						printf("Clasificacion del juego: %s\n", compras[i].Clasi.c_str());
						printf("Caracteristicas del juego: %s\n", compras[i].Carac.c_str());
						printf("Descripcion del juego: %s\n", compras[i].Desc.c_str());
						printf("Genero del juego: %s\n", compras[i].Genero.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);

					}
				}
			}
			else
			{
				for (int i = 0; i < 3; i++)
				{
					if (compras[i].NumArt != 0)
					{
						printf("ID CONTRATO: %d \n", compras[i].idcontrato);
						printf("Nombre del Videojuego: %s\n", compras[i].NomVid.c_str());
						printf("num de articulo: %d \n", compras[i].NumArt);
						//proveedor
						printf("proveedor %s", compras[i].proveedor.c_str());
						printf("Ano de lanzamiento: %s\n", compras[i].Lanz.c_str());
						printf("Clasificacion del juego: %s\n", compras[i].Clasi.c_str());
						printf("Caracteristicas del juego: %s\n", compras[i].Carac.c_str());
						printf("Descripcion del juego: %s\n", compras[i].Desc.c_str());
						printf("Genero del juego: %s\n", compras[i].Genero.c_str());
						printf("subtotal: %f \n", compras[i].subtotal);
						printf("iva: %f \n", compras[i].iva);
						printf("total: %f \n", compras[i].total);
					}
				}
			}
			break;

		case 5:
			system("cls");
			break;
			
		case 6:
			printf("saliendo... \n");
			break;
		default:
			printf("intente denuevo... \n");
			break;
		}
	} while (opcion != 6);
	system("pause");
}