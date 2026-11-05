#include "../Localization.hpp"
#include <string>
#include "../UI/UI.hpp"

#include "../Platform/Platform.hpp"
#include "../ViewFunctions.hpp"

class RebootPage : public IPage
{
	public:
		RebootPage()
		{
			Name = "Reboot";
		}
		
		void Render(int X, int Y) 
		{
			Utils::ImGuiSetupPage(this, X, Y);
			ImGui::PushFont(font30);
			ImGui::SetCursorPos({ 5, 10 });

			ImGui::TextUnformatted(Lang::T("Rebooting your console will apply the changes you made."));
			ImGui::TextWrapped(Lang::T("This is a shortcut to the system's reboot button. If your CFW doesn't provide reboot to payload you will need a way to inject a payload from RCM."));
			if (ImGui::Button(Lang::T("Reboot")))
			{
				PlatformReboot();
			}
			PAGE_RESET_FOCUS;
			
			ImGui::PopFont();
			Utils::ImGuiCloseWin();
		}
		
		void Update() override
		{
			if (Utils::PageLeaveFocusInput())
				Parent->PageLeaveFocus(this);
		}
};