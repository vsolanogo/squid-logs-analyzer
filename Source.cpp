#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "UKR");
	cout << "\nwritten in Jul 2015";
	ifstream RR;
	double  bytes, MegaBytes[5000][1], x;
	int k = 1, z = 0, numberSTR = 0, numberIP = 1, i = 0, size, krapok = 0, j = 0, krapokNumber = 0;
	char a[8000], b[8000], c[8000], adresa[500], action, action2, site[50];
	char *sylkaB, *sylkaFree, *sylkaBytes, *sylkaURL, *sylka2;
	char **SortX = new char*[1];
	SortX[1] = new char[1000];
	char *znaki = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
	static char *name[] = { "co", "org", "com", "net", "gov", "edu", "school", "me" };

	do
	{
		cout << "\n\nselect the action:\n1-Analyze access.log\n2-Exit\n";
		while (1)
		{
			cin >> action;
			if (action == '1' || action == '2')
				break;
			cout << "\nError! Available value 1,2!\n";
		}
		switch (action)
		{
		case '1':
			cout << "write file location (example - D:\\\\log\\\\access.log):\n";
			cin >> adresa;
			RR.open(adresa, ios::in);

			if (!RR.is_open())
				cout << "\n" << adresa << " - incorrect location or file can not be open\n";
			else
			{

				RR.close();
				do
				{
					cout << "\n\n\t1-traffic by IP address\n\t2-traffic by type of data\n\t3-most popular site\n\t4-which users visited the site\n\t5-which sites visited the IP address\n\t6-back\n";
					while (1)
					{
						cin >> action2;
						if (action2 == '1' || action2 == '2' || action2 == '3' || action2 == '4' || action2 == '5' || action2 == '6')
							break;
						cout << "\nError! Available value 1,2,3,4,5!\n";
					}
					switch (action2)
					{
					case '1':
					{RR.open(adresa, ios::in);

					char **MasyvIP = new char*[2000];
					for (i = 0; i < 2000; i++)
						MasyvIP[i] = new char[20];

					while (1)
					{
						RR.getline(b, 7990);
						if (strlen(b) == 0)
							break;
						sylkaB = b;
						sylkaB = strchr(sylkaB, ' ');
						*sylkaB = '\0';
						if (*(sylkaB + 1) == ' ')
						{
							while (1)
							{
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';
								if (*(sylkaB + 1) != ' ')
								{
									sylkaFree = sylkaB + 1;
									break;
								}
							}
						}
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaFree = sylkaB + 1;
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaBytes = sylkaB + 1;
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';

						for (i = 0; i < numberIP; i++)
						{
							if ((strcmp(sylkaFree, MasyvIP[i])) == 0)
							{
								bytes = atof(sylkaBytes);
								MegaBytes[i][0] = MegaBytes[i][0] + (bytes / 1000000);
								break;
							}
							else if (i == (numberIP - 1))
							{
								strcpy(MasyvIP[numberIP - 1], sylkaFree);
								bytes = atof(sylkaBytes);
								MegaBytes[numberIP - 1][0] = (bytes / 1000000);
								numberIP++;
								break;
							}
						}
						z++;
						if (z % 100000 == 0)
						{
							cout << ". ";
						}

					}
					for (i = 0; i<numberIP - 1; i++)
					{
						for (j = numberIP - 2; j>i; j--)
						{
							if (MegaBytes[j - 1][0]>MegaBytes[j][0])
							{
								x = MegaBytes[j - 1][0];
								strcpy(SortX[1], MasyvIP[j - 1]);
								MegaBytes[j - 1][0] = MegaBytes[j][0];
								strcpy(MasyvIP[j - 1], MasyvIP[j]);
								MegaBytes[j][0] = x;
								strcpy(MasyvIP[j], SortX[1]);
							}
						}
					}
					cout << "\nfile lines-" << z << endl;
					cout << "\n" << "� \t" << "IP Address\t" << "data received by user";
					for (i = 0; i < numberIP - 1; i++)
					{
						cout << "\n" << (i + 1) << ".\t" << MasyvIP[i] << "\t\t" << MegaBytes[i][0] << "    MB";
					}
					for (i = 0; i < 2000; i++)
						delete[]MasyvIP[i];
					delete[]MasyvIP;
					numberIP = 1;
					RR.close();
					z = 0;
					break;
					}
					case '2':
					{RR.open(adresa, ios::in);
					char **MasyvIP = new char*[300];
					for (i = 0; i < 300; i++)
						MasyvIP[i] = new char[200];
					while (1)
					{
						RR.getline(b, 7990);
						if (strlen(b) == 0)
							break;
						strcpy(a, b);
						sylkaFree = strrchr(a, ' ');
						sylkaB = b;
						sylkaB = strchr(sylkaB, ' ');
						*sylkaB = '\0';
						if (*(sylkaB + 1) == ' ')
						{
							while (1)
							{
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';
								if (*(sylkaB + 1) != ' ')
								{
									break;
								}
							}
						}
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaBytes = sylkaB + 1;
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						for (i = 0; i < numberIP; i++)
						{
							if ((strcmp(sylkaFree, MasyvIP[i])) == 0)
							{
								bytes = atof(sylkaBytes);
								MegaBytes[i][0] = MegaBytes[i][0] + (bytes / 1000000);
								break;
							}
							else if (i == (numberIP - 1))
							{
								strcpy(MasyvIP[numberIP - 1], sylkaFree);
								bytes = atof(sylkaBytes);
								MegaBytes[numberIP - 1][0] = (bytes / 1000000);
								numberIP++;
								break;
							}
						}
						z++;
						if (z % 100000 == 0)
						{
							cout << ". ";
						}
					}
					//sortabling
					for (i = 0; i<numberIP - 1; i++)
					{
						for (j = numberIP - 2; j>i; j--)
						{
							if (MegaBytes[j - 1][0]>MegaBytes[j][0])
							{
								x = MegaBytes[j - 1][0];
								strcpy(SortX[1], MasyvIP[j - 1]);
								MegaBytes[j - 1][0] = MegaBytes[j][0];
								strcpy(MasyvIP[j - 1], MasyvIP[j]);
								MegaBytes[j][0] = x;
								strcpy(MasyvIP[j], SortX[1]);
							}
						}
					}
					cout << "\n" << "� \t" << "data received by user" << "\tdata type";
					for (i = 0; i < numberIP - 1; i++)
					{
						cout << "\n" << (i + 1) << ". \t" << MegaBytes[i][0] << "    MB" << "\t" << MasyvIP[i];
					}
					for (i = 0; i < 300; i++)
						delete[]MasyvIP[i];
					delete[]MasyvIP;
					numberIP = 1;
					RR.close();
					z = 0;
					break;
					}
					case '3':
					{RR.open(adresa, ios::in);
					char **MasyvIP = new char*[3000];//����� �����
					for (i = 0; i < 3000; i++)
						MasyvIP[i] = new char[200];
					while (1)
					{
						krapok = 0;
						RR.getline(b, 7990);
						if (strlen(b) == 0)
							break;
						sylkaB = b;
						sylkaB = strchr(sylkaB, ' ');
						*sylkaB = '\0';
						if (*(sylkaB + 1) == ' ')
						{
							while (1)
							{
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';
								if (*(sylkaB + 1) != ' ')
								{
									break;
								}
							}
						}
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaBytes = (sylkaB + 1);
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						sylkaFree = sylkaB + 1;
						sylkaB = strchr(sylkaB + 1, ' ');
						*sylkaB = '\0';
						if (strchr(sylkaFree, '/'))
						{
							sylkaFree = strchr(sylkaFree, '/');
							*sylkaFree = '\0';
							sylkaFree = strchr(sylkaFree + 1, '/');
							*sylkaFree = '\0';
							sylkaURL = (sylkaFree + 1);
							if (strchr(sylkaFree + 1, '/'))
							{
								sylkaFree = strchr(sylkaFree + 1, '/');
								*sylkaFree = '\0';
							}
						}
						else
						{
							sylkaURL = sylkaFree;
						}
						strcpy(c, sylkaURL);
						if (strrchr(sylkaURL, '.'))
						{
							if (strpbrk(sylkaURL, znaki))
							{
								_strrev(sylkaURL);
								size = strlen(sylkaURL);
								for (i = 0; i < size; i++)
								{
									if (*(sylkaURL + i) == '.')
									{
										krapok++;

									}
									if (krapok == 2)
									{
										*(sylkaURL + i) = '\0';
										break;
									}
								}
								_strrev(sylkaURL);
							}
							strcpy(a, sylkaURL);
							sylka2 = strchr(a, '.');
							*sylka2 = '\0';
							krapok = 0;
							for (i = 0; i < 8; i++)
							{
								if (strstr(name[i], a))//drugii domen
								{
									if (strpbrk(sylkaURL, znaki))
									{
										sylkaURL = c;
										_strrev(sylkaURL);
										size = strlen(sylkaURL);
										for (i = 0; i < size; i++)
										{
											if (*(sylkaURL + i) == '.')
											{
												krapok++;
											}
											if (krapok == 3)
											{
												*(sylkaURL + i) = '\0';
												break;
											}
										}
										_strrev(sylkaURL);
									}
									break;
								}
							}

							for (i = 0; i < numberIP; i++)
							{
								if ((strcmp(sylkaURL, MasyvIP[i])) == 0)
								{
									bytes = atof(sylkaBytes);
									MegaBytes[i][0] = MegaBytes[i][0] + (bytes / 1000000);
									break;
								}
								else if (i == (numberIP - 1))
								{
									strcpy(MasyvIP[numberIP - 1], sylkaURL);
									bytes = atof(sylkaBytes);
									MegaBytes[numberIP - 1][0] = (bytes / 1000000);
									numberIP++;
									break;
								}
							}
						}
						z++;
						if (z % 100000 == 0)
						{
							cout << ". ";
						}
					}
					//sortabling
					for (i = 0; i<numberIP - 1; i++) {
						for (j = numberIP - 2; j>i; j--)
						{
							if (MegaBytes[j - 1][0]>MegaBytes[j][0])
							{
								x = MegaBytes[j - 1][0];
								strcpy(SortX[1], MasyvIP[j - 1]);
								MegaBytes[j - 1][0] = MegaBytes[j][0];
								strcpy(MasyvIP[j - 1], MasyvIP[j]);
								MegaBytes[j][0] = x;
								strcpy(MasyvIP[j], SortX[1]);
							}
						}
					}

					cout << "\n" << "� \t" << "MB\t" << "\t\tURL";
					for (i = 0; i < numberIP - 1; i++)
					{
						cout << "\n" << (i + 1) << ". \t" << MegaBytes[i][0] << "    MB" << "\t" << MasyvIP[i];
					}
					for (i = 0; i < 3000; i++)
						delete[]MasyvIP[i];
					delete[]MasyvIP;
					numberIP = 1;
					RR.close();
					z = 0;
					break;
					}
					case '4':
					{
						RR.open(adresa, ios::in);
						cout << "\nwrite the site-";
						cin >> site;
						char *etuut = site;
						char **MasyvIP = new char*[1000];
						for (i = 0; i < 1000; i++)
							MasyvIP[i] = new char[20];

						while (1)
						{
							RR.getline(b, 7990);
							if (strlen(b) == 0)
								break;
							sylkaB = b;
							if (strstr(sylkaB, etuut))
							{
								sylkaB = b;
								sylkaB = strchr(sylkaB, ' ');
								*sylkaB = '\0';
								if (*(sylkaB + 1) == ' ')
								{
									while (1)
									{
										sylkaB = strchr(sylkaB + 1, ' ');
										*sylkaB = '\0';
										if (*(sylkaB + 1) != ' ')
										{
											sylkaFree = sylkaB + 1;
											break;
										}
									}
								}
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';
								sylkaFree = sylkaB + 1;
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';
								sylkaBytes = sylkaB + 1;
								sylkaB = strchr(sylkaB + 1, ' ');
								*sylkaB = '\0';

								for (i = 0; i < numberIP; i++)
								{
									if ((strcmp(sylkaFree, MasyvIP[i])) == 0)
									{
										bytes = atof(sylkaBytes);
										MegaBytes[i][0] = MegaBytes[i][0] + (bytes / 1000000);
										break;
									}
									else if (i == (numberIP - 1))
									{
										strcpy(MasyvIP[numberIP - 1], sylkaFree);
										bytes = atof(sylkaBytes);
										MegaBytes[numberIP - 1][0] = (bytes / 1000000);
										numberIP++;
										break;
									}
								}
								z++;
								if (z % 10000 == 0)
								{
									cout << ". ";
								}

							}
						}

						//sortabling
						for (i = 0; i<numberIP - 1; i++)
						{
							for (j = numberIP - 2; j>i; j--)
							{
								if (MegaBytes[j - 1][0]>MegaBytes[j][0])
								{
									x = MegaBytes[j - 1][0];
									strcpy(SortX[1], MasyvIP[j - 1]);
									MegaBytes[j - 1][0] = MegaBytes[j][0];
									strcpy(MasyvIP[j - 1], MasyvIP[j]);
									MegaBytes[j][0] = x;
									strcpy(MasyvIP[j], SortX[1]);
								}
							}
						}
						cout << "\n" << "� \t" << "IP address\t" << "data received by user";
						for (i = 0; i < numberIP - 1; i++)
						{
							cout << "\n" << (i + 1) << ".\t" << MasyvIP[i] << "\t\t" << MegaBytes[i][0] << "    MB";
						}
						for (i = 0; i < 1000; i++)
							delete[]MasyvIP[i];
						delete[]MasyvIP;
						numberIP = 1;
						RR.close();
						z = 0;
					}
					break;
					case '5':
					{RR.open(adresa, ios::in);

					char **MasyvIP = new char*[3000];
					for (i = 0; i < 3000; i++)
						MasyvIP[i] = new char[200];
					cout << "\nwrite the IP address-";
					cin >> site;
					char *etuut = site;
					while (1)
					{
						krapok = 0;
						RR.getline(b, 7990);
						if (strlen(b) == 0)
							break;
						sylkaB = b;
						if (strstr(sylkaB, etuut))
						{
							sylkaB = strchr(sylkaB, ' ');
							*sylkaB = '\0';
							if (*(sylkaB + 1) == ' ')
							{
								while (1)
								{
									sylkaB = strchr(sylkaB + 1, ' ');
									*sylkaB = '\0';
									if (*(sylkaB + 1) != ' ')
									{
										break;
									}
								}
							}
							sylkaB = strchr(sylkaB + 1, ' ');
							*sylkaB = '\0';
							sylkaB = strchr(sylkaB + 1, ' ');
							*sylkaB = '\0';
							sylkaB = strchr(sylkaB + 1, ' ');
							*sylkaB = '\0';
							sylkaBytes = (sylkaB + 1);
							sylkaB = strchr(sylkaB + 1, ' ');
							*sylkaB = '\0';
							sylkaB = strchr(sylkaB + 1, ' ');
							*sylkaB = '\0';
							sylkaFree = sylkaB + 1;
							sylkaB = strchr(sylkaB + 1, ' ');
							*sylkaB = '\0';
							if (strchr(sylkaFree, '/'))
							{
								sylkaFree = strchr(sylkaFree, '/');
								*sylkaFree = '\0';
								sylkaFree = strchr(sylkaFree + 1, '/');
								*sylkaFree = '\0';
								sylkaURL = (sylkaFree + 1);
								if (strchr(sylkaFree + 1, '/'))
								{
									sylkaFree = strchr(sylkaFree + 1, '/');
									*sylkaFree = '\0';
								}
							}
							else
							{
								sylkaURL = sylkaFree;
							}
							strcpy(c, sylkaURL);
							if (strrchr(sylkaURL, '.'))
							{
								if (strpbrk(sylkaURL, znaki))
								{
									_strrev(sylkaURL);
									size = strlen(sylkaURL);
									for (i = 0; i < size; i++)
									{
										if (*(sylkaURL + i) == '.')
										{
											krapok++;

										}
										if (krapok == 2)
										{
											*(sylkaURL + i) = '\0';
											break;
										}
									}
									_strrev(sylkaURL);
								}
								strcpy(a, sylkaURL);
								sylka2 = strchr(a, '.');
								*sylka2 = '\0';
								krapok = 0;
								for (i = 0; i < 8; i++)
								{
									if (strstr(name[i], a))//drugii domen
									{
										if (strpbrk(sylkaURL, znaki))
										{
											sylkaURL = c;
											_strrev(sylkaURL);
											size = strlen(sylkaURL);
											for (i = 0; i < size; i++)
											{
												if (*(sylkaURL + i) == '.')
												{
													krapok++;
												}
												if (krapok == 3)
												{
													*(sylkaURL + i) = '\0';
													break;
												}
											}
											_strrev(sylkaURL);
										}
										break;
									}
								}

								for (i = 0; i < numberIP; i++)
								{
									if ((strcmp(sylkaURL, MasyvIP[i])) == 0)
									{
										bytes = atof(sylkaBytes);
										MegaBytes[i][0] = MegaBytes[i][0] + (bytes / 1000000);
										break;
									}
									else if (i == (numberIP - 1))
									{
										strcpy(MasyvIP[numberIP - 1], sylkaURL);
										bytes = atof(sylkaBytes);
										MegaBytes[numberIP - 1][0] = (bytes / 1000000);
										numberIP++;
										break;
									}
								}
							}
							z++;
							if (z % 100000 == 0)
							{
								cout << ". ";
							}
						}
					}
					//sortabling
					for (i = 0; i<numberIP - 1; i++) {
						for (j = numberIP - 2; j>i; j--)
						{
							if (MegaBytes[j - 1][0]>MegaBytes[j][0])
							{
								x = MegaBytes[j - 1][0];
								strcpy(SortX[1], MasyvIP[j - 1]);
								MegaBytes[j - 1][0] = MegaBytes[j][0];
								strcpy(MasyvIP[j - 1], MasyvIP[j]);
								MegaBytes[j][0] = x;
								strcpy(MasyvIP[j], SortX[1]);
							}
						}
					}

					cout << "\n" << "� \t" << "MB\t" << "\t\tURL";
					for (i = 0; i < numberIP - 1; i++)
					{
						cout << "\n" << (i + 1) << ". \t" << MegaBytes[i][0] << "    MB" << "\t" << MasyvIP[i];
					}
					for (i = 0; i < 3000; i++)
						delete[]MasyvIP[i];
					delete[]MasyvIP;
					numberIP = 1;
					RR.close();
					z = 0;
					break;
					}
					case '6':
						break;
					}
				} while (action2 != '6');
			}
			break;
		case '2':
			break;
		}
	} while (action != '2');

}