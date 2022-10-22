#ifndef FILEZILLA_INTERFACE_OPTIONSPAG_PASSWORDS_HEADER
#define FILEZILLA_INTERFACE_OPTIONSPAG_PASSWORDS_HEADER

#include "optionspage.h"

class COptionsPagePasswords final : public COptionsPage
{
public:
	COptionsPagePasswords();
	virtual ~COptionsPagePasswords();

	virtual bool LoadPage() override;
	virtual bool SavePage() override;
	virtual bool Validate() override;

protected:
	struct impl;
	std::unique_ptr<impl> impl_;

	virtual bool CreateControls(wxWindow* parent) override;
};

#endif
