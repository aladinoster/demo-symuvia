//------------------------------------------
// Fonctions export�es de la DLL SYMUVIA
//------------------------------------------

#include <string>
#include "TrafficState.h"

// Chargement du scenario
__declspec(dllexport) bool __cdecl SymLoadNetwork(std::string sTmpXmlDataFile, std::string sScenarioID = "");
__declspec(dllexport) bool __cdecl SymLoadNetwork(std::string sTmpXmlDataFile, eveShared::SimulationInfo * &pSInfo, eveShared::SymuviaNetwork * &pSNetwork, std::string sScenarioID = "");

// Sortie de la simulation
__declspec(dllexport) int  __cdecl SymQuit();

// ----- Simulation compl�te -----

// Ex�cution compl�te d'une simulation
__declspec(dllexport) bool __cdecl SymRun();

// Ex�cution compl�te d'une simulation de trafic
__declspec(dllexport) bool __cdecl SymRunTraffic();

// Ex�cution compl�te d'une simulation des �missions acoustiques
__declspec(dllexport) bool __cdecl SymRunAcousticEmissions();

// Ex�cution compl�te d'une simulation des �missions atmosph�riques
__declspec(dllexport) bool __cdecl SymRunAirEmissions();


// ----- Simulation pas � pas -----

// Ex�cution d'un pas de temps d'une simulation (et sortie de l'�tat de la simulation)
__declspec(dllexport) bool __cdecl SymRunNextStep(std::string &sXmlFluxInstant, bool bTrace, bool &bNEnd);
__declspec(dllexport) bool __cdecl SymRunNextStep(eveShared::TrafficState * &pTrafficEVE, bool bTrace, bool &bNEnd);

__declspec(dllexport) char* __cdecl SymRunNextStepNode(bool bTrace, bool &bNEnd);

// Ex�cution d'un pas de temps d'une simulation de trafic
__declspec(dllexport) bool __cdecl SymRunNextStepTraffic(std::string &sXmlFluxInstant, bool bTrace, bool &bNEnd);
__declspec(dllexport) bool __cdecl SymRunNextStepTraffic(eveShared::TrafficState * &pTrafficEVE, bool bTrace, bool &bNEnd);

// Ex�cution d'un pas de temps d'une simulation de trafic et d'acoustique
__declspec(dllexport) bool __cdecl SymRunNextStepTrafficAcoustic(std::string &sXmlFluxInstant, bool bCel, bool bSrc, bool bTrace, bool &bNEnd);
__declspec(dllexport) bool __cdecl SymRunNextStepTrafficAcoustic(eveShared::TrafficState * &pTrafficEVE, bool bCel, bool bSrc, bool bTrace, bool &bNEnd);

// Ex�cution d'un pas de temps d'une simulation de trafic et d'atmospherique
__declspec(dllexport) bool __cdecl SymRunNextStepTrafficAtmospheric(std::string &sXmlFluxInstant, bool bTrace, bool &bNEnd);

// D�placement vers un pas de temps d'indice donn�
__declspec(dllexport) bool __cdecl SymRunToStep(int nStep, std::string &sXmlFluxInstant, bool bTrace, bool &bNEnd);
__declspec(dllexport) bool __cdecl SymRunToStep(int nStep, eveShared::TrafficState * &pTrafficEVE, bool bTrace, bool &bNEnd);

// R�initialisation de la simulation au premier instant
__declspec(dllexport) int  __cdecl SymReset(); 

// M�nage
__declspec(dllexport) bool __cdecl SymRunDeleteTraffic(eveShared::TrafficState * &pTrafficEVE);

// ----- Mise � jour des scenari -----

// Mise � jour du scenario
__declspec(dllexport) bool __cdecl SymUpdateNetwork(std::string sXmlDataFile);

// Mise � jour d'un plan de feux du r�seau
__declspec(dllexport) int  __cdecl SymSendSignalPlan(std::string sCDF, std::string sSP);

// Mise � jour d'une vitesse r�glementaire d'un tron�on du r�seau
__declspec(dllexport) int  __cdecl SymSendSpeedLimit(std::string sSection, std::string sVehType, double dbSpeedLimit);

// Affectation d'itin�raires pour une OD
__declspec(dllexport) int __cdecl SymSetRoutes(char* originId, char* destinationId, char* typeVeh, char** links[] , double coeffs[], int iLength);

// ----- Pilotage des v�hicules -----

// Cr�ation d'un v�hicule
__declspec(dllexport) int __cdecl SymCreateVehicle(std::wstring sType, std::wstring sEntree, std::wstring sSortie, int nVoie, double dbt);

// Pilotage d'un v�hicule
__declspec(dllexport) int __cdecl SymDriveVehicle(int nID, std::wstring	sTroncon, int nVoie, double dbPos, bool bForce);

// Modification d'un itin�raire d'un v�hicule
__declspec(dllexport) int __cdecl SymAlterRoute(int nIdVeh, char*  links[] , int iLength);

// Retourne les itin�raires actuels d'une liste de v�hicules
__declspec(dllexport) char* __cdecl SymGetVehiclesPaths( char*  vehiculeId[], int iLength);

// ----- Sorties compl�mentaires -----

// G�n�ration du reseau EVE
__declspec(dllimport) bool __cdecl SymGenEveNetwork(eveShared::EveNetwork * &pNetwork);

// G�n�ration de la liste des cellules acoustiques
__declspec(dllexport) bool __cdecl SymGenAcousticCells();

// ----- S�rialisation -----

// Sauvegarde de l'�tat courant vers un fichier XML
__declspec(dllexport) void __cdecl SymSaveState(char* sXmlDataFile);

// Chargement d'un �tat sauvegard� depuis un fichier XML
__declspec(dllexport) void __cdecl SymLoadState(char* sXmlDataFile);


// ----- Post-traitement -----

// Module de calcul de d�c�l�ration
__declspec(dllexport) bool __cdecl SymDeceleration(double dbRate);

// Module de calcul des trajectories
__declspec(dllexport) bool __cdecl SymGenTrajectories();

// Module PHEM
__declspec(dllexport) bool __cdecl SymGenPHEMFiles(std::string sOutputDirectory, std::vector<int> IDs = std::vector<int>());
__declspec(dllexport) bool __cdecl SymRunPHEM(std::string sPHEMPath, std::string sDRIFile);
