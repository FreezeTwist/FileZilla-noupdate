#ifndef FILEZILLA_INTERFACE_OPTIONS_HEADER
#define FILEZILLA_INTERFACE_OPTIONS_HEADER

#include "../include/engine_options.h"

#include "../commonui/options.h"

#include <wx/timer.h>

enum interfaceOptions : unsigned int
{
	// Default/internal options
	OPTION_DEFAULT_CACHE_DIR,

	OPTION_NUMTRANSFERS,
	OPTION_LANGUAGE,
	OPTION_CONCURRENTDOWNLOADLIMIT,
	OPTION_CONCURRENTUPLOADLIMIT,
	OPTION_DEBUG_MENU,
	OPTION_FILEEXISTS_DOWNLOAD,
	OPTION_FILEEXISTS_UPLOAD,
	OPTION_ASCIIRESUME,
	OPTION_GREETINGVERSION,
	OPTION_GREETINGRESOURCES,
	OPTION_ONETIME_DIALOGS,
	OPTION_SHOW_TREE_LOCAL,
	OPTION_SHOW_TREE_REMOTE,
	OPTION_FILEPANE_LAYOUT,
	OPTION_FILEPANE_SWAP,
	OPTION_FILELIST_DIRSORT,
	OPTION_FILELIST_NAMESORT,
	OPTION_QUEUE_SUCCESSFUL_AUTOCLEAR,
	OPTION_QUEUE_COLUMN_WIDTHS,
	OPTION_LOCALFILELIST_COLUMN_WIDTHS,
	OPTION_REMOTEFILELIST_COLUMN_WIDTHS,
	OPTION_MAINWINDOW_POSITION,
	OPTION_MAINWINDOW_SPLITTER_POSITION,
	OPTION_LOCALFILELIST_SORTORDER,
	OPTION_REMOTEFILELIST_SORTORDER,
	OPTION_TIME_FORMAT,
	OPTION_DATE_FORMAT,
	OPTION_SHOW_MESSAGELOG,
	OPTION_SHOW_QUEUE,
	OPTION_EDIT_DEFAULTEDITOR,
	OPTION_EDIT_ALWAYSDEFAULT,
	OPTION_EDIT_CUSTOMASSOCIATIONS,
	OPTION_COMPARISONMODE,
	OPTION_SITEMANAGER_POSITION,
	OPTION_ICONS_THEME,
	OPTION_ICONS_SCALE,
	OPTION_MESSAGELOG_TIMESTAMP,
	OPTION_SITEMANAGER_LASTSELECTED,
	OPTION_LOCALFILELIST_COLUMN_SHOWN,
	OPTION_REMOTEFILELIST_COLUMN_SHOWN,
	OPTION_LOCALFILELIST_COLUMN_ORDER,
	OPTION_REMOTEFILELIST_COLUMN_ORDER,
	OPTION_FILELIST_STATUSBAR,
	OPTION_FILTERTOGGLESTATE,
	OPTION_SHOW_QUICKCONNECT,
	OPTION_MESSAGELOG_POSITION,
	OPTION_DOUBLECLICK_ACTION_FILE,
	OPTION_DOUBLECLICK_ACTION_DIRECTORY,
	OPTION_MINIMIZE_TRAY,
	OPTION_SEARCH_COLUMN_WIDTHS,
	OPTION_SEARCH_COLUMN_SHOWN,
	OPTION_SEARCH_COLUMN_ORDER,
	OPTION_SEARCH_SIZE,
	OPTION_COMPARE_HIDEIDENTICAL,
	OPTION_SEARCH_SORTORDER,
	OPTION_EDIT_TRACK_LOCAL,
	OPTION_PREVENT_IDLESLEEP,
	OPTION_FILTEREDIT_SIZE,
	OPTION_INVALID_CHAR_REPLACE_ENABLE,
	OPTION_INVALID_CHAR_REPLACE,
	OPTION_ALREADYCONNECTED_CHOICE,
	OPTION_EDITSTATUSDIALOG_SIZE,
	OPTION_SPEED_DISPLAY,
	OPTION_TOOLBAR_HIDDEN,
	OPTION_STRIP_VMS_REVISION,
	OPTION_STARTUP_ACTION,
	OPTION_PROMPTPASSWORDSAVE,
	OPTION_PERSISTENT_CHOICES,
	OPTION_QUEUE_COMPLETION_ACTION,
	OPTION_QUEUE_COMPLETION_COMMAND,
	OPTION_DND_DISABLED,
	OPTION_DISABLE_UPDATE_FOOTER,
	OPTION_TAB_DATA,
	OPTION_SHOWN_OVERLAY,

	// Has to be last element
	OPTIONS_NUM
};

optionsIndex mapOption(interfaceOptions opt);

class COptions final : public wxEvtHandler, public XmlOptions
{
public:
	COptions();
	virtual ~COptions();

	COptions(COptions const&) = delete;
	COptions& operator=(COptions const&) = delete;

	static COptions* Get();

	CLocalPath GetCacheDirectory();

	void Save(bool processChanged = true);

protected:
	virtual void notify_changed() override;
	virtual void on_dirty() override;
	static COptions* m_theOptions;

	wxTimer m_save_timer;

	DECLARE_EVENT_TABLE()
	void OnTimer(wxTimerEvent& event);
};

#endif
