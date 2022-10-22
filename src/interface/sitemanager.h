#ifndef FILEZILLA_INTERFACE_SITEMANAGER_HEADER
#define FILEZILLA_INTERFACE_SITEMANAGER_HEADER

#include "xmlfunctions.h"
#include "../commonui/site_manager.h"

#include <wx/treectrl.h>

class CLoginManager;
class CSiteManagerDialog;
class CSiteManager : public site_manager
{
	friend class CSiteManagerDialog;
public:
	static bool Load(CSiteManagerXmlHandler& handler);
	using site_manager::Load;

	// This function also clears the Id map
	static std::unique_ptr<wxMenu> GetSitesMenu();
	static void ClearIdMap();
	static std::unique_ptr<Site> GetSiteById(int id);

	static std::pair<std::unique_ptr<Site>, Bookmark> GetSiteByPath(std::wstring const& sitePath, bool printErrors = true);

	static std::wstring AddServer(Site site);
	static bool AddBookmark(std::wstring sitePath, wxString const& name, wxString const& local_dir, CServerPath const& remote_dir, bool sync, bool comparison);
	static bool ClearBookmarks(std::wstring sitePath);

	static void Rewrite(CLoginManager & loginManager, bool on_failure_set_to_ask);

	static bool HasSites();

	static int GetColourIndex(site_colour const& c);
	static wxString GetColourName(int i);

	static bool ImportSites(pugi::xml_node sites);

protected:
	static bool ImportSites(pugi::xml_node sitesToImport, pugi::xml_node existingSites);

	static void Rewrite(CLoginManager & loginManager, pugi::xml_node element, bool on_failure_set_to_ask);
	static void Save(pugi::xml_node element, Site const& site);

	static std::map<int, std::unique_ptr<Site>> m_idMap;

	// The map maps event id's to sites
	static std::unique_ptr<wxMenu> GetSitesMenu_Predefined(std::map<int, std::unique_ptr<Site>> &idMap);
	static bool LoadPredefined(CSiteManagerXmlHandler& handler);
};

#endif
