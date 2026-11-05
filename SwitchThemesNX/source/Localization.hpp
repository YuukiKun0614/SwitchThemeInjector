#pragma once
// NXThemes Installer Japanese localization: bilingual UI + persistent language choice.
// All bundled translations are original. Font glyphs come from the Switch OS.
#include <string>
#include <unordered_map>
#include <fstream>
#include <filesystem>
#include <system_error>
#include <algorithm>

namespace Lang {
    enum class Language { English = 0, Japanese = 1 };
    inline Language current = Language::English;
    inline bool japanFontAvailable = false;
    inline std::unordered_map<std::string, std::string>& Dictionary() {
        static std::unordered_map<std::string, std::string> translations = {
      {"Themes", "テーマ一覧"},
      {"Download themes", "テーマのダウンロード"},
      {"Uninstall theme", "テーマの削除"},
      {"Dump home menu", "HOMEメニューの抽出"},
      {"Settings", "設定"},
      {"Credits", "クレジット"},
      {"Reboot", "再起動"},
      {"Quit", "終了"},
      {"Applet mode", "アプレットモード"},
      {"Language", "言語"},
      {"Choose a display language. Changes are saved automatically and used on the next launch.", "表示言語を選択してください。変更は自動保存され、次回起動時にも引き継がれます。"},
      {"English", "英語"},
      {"Japanese / 日本語", "日本語"},
      {"Update detection sysmodule v3", "アップデート検出システムモジュール v3"},
      {"This sysmodule automatically removes themes when the system firmware changes. This prevents crashes after updates but you still need to remove leftover files from the uninstall page after updating.", "本体のシステム更新時にテーマを自動的に解除します。更新後の起動エラーを予防できますが、残ったファイルはテーマ削除画面から取り除いてください。"},
      {"The sysmodule v%d is currently installed.", "システムモジュール v%d はインストール済みです。"},
      {"The sysmodule v%d is currently installed. A new version is available.", "システムモジュール v%d がインストール済みです。新しいバージョンがあります。"},
      {"The sysmodule is currently not installed.", "システムモジュールは未インストールです。"},
      {"This version of the theme installer does not contain the sysmodule binary.", "このテーマインストーラーにはシステムモジュールが含まれていません。"},
      {"This update fixes a number of bugs reported by users.", "この更新には複数の不具合修正が含まれます。"},
      {"Uninstall", "削除"},
      {"Uninstall everything", "テーマ関連をすべて削除"},
      {"Install now", "今すぐインストール"},
      {"Update now", "今すぐ更新"},
      {"NXTheme settings", "NXThemeの設定"},
      {"These settings only apply for installing nxthemes and are not saved, you have to switch them back every time you launch this app", "以下のテーマ互換性設定は保存されず、アプリ起動ごとに初期値へ戻ります。"},
      {"Home menu layout compatibility options", "HOME画面レイアウトの互換性"},
      {"Decide automatically (default)", "自動判定（推奨）"},
      {"Force original home menu applet icons (firmware <= 10.0)", "旧HOME画面アイコンを強制（FW 10.0以前）"},
      {"Force home menu layout with the NS online icon (firmware 11.0)", "Nintendo Switch Onlineアイコン付きレイアウトを強制（FW 11.0）"},
      {"Do not apply compatibility fixes", "互換性修正を適用しない"},
      {"Layout parts options", "レイアウト構成の設定"},
      {"Enable custom icons", "カスタムアイコンを有効にする"},
      {"Enable extra layouts (eg. common.szs)", "追加レイアウトを有効にする（common.szsなど）"},
      {"Use these options to uninstall the currently installed themes.", "現在適用中のテーマを削除できます。"},
      {"Remove the current theme", "現在のテーマを削除"},
      {"Remove the hekate boot logo", "Hekate起動ロゴを削除"},
      {"In case you're facing unexpected crashes, use the following option to remove everything related to themes including fsmitm folders, the version check sysmodule and theme patches.", "テーマ適用後に起動エラーが発生する場合、以下の操作でテーマ関連のファイル、システムモジュール、パッチをまとめて削除できます。"},
      {"Done, all the installed themes have been removed, restart your console to apply the changes", "テーマの削除が完了しました。変更の反映には再起動してください。"},
      {"The hekate boot logo has been removed, restart your console to apply the changes", "Hekateの起動ロゴを削除しました。再起動して反映してください。"},
      {"The sysmodule has been installed. Restart your console to apply the changes.", "システムモジュールをインストールしました。再起動して反映してください。"},
      {"The sysmodule has been uninstalled. Restart your console to apply the changes.", "システムモジュールを削除しました。再起動して反映してください。"},
      {"Loading system info...", "システム情報を読み込み中…"},
      {"Loading themes list...", "テーマ一覧を読み込み中…"},
      {"This folder is empty.", "このフォルダーは空です。"},
      {"Go to the previous folder", "前のフォルダーに戻る"},
      {"There's nothing here, copy your themes in the themes folder on your sd and try again.\n\nIf you do have a themes folder in your sd with themes make sure that the name is all lowercase and check your SD for corruption.\n\nYou can find more themes on themezer.net", "テーマがありません。SDカードのthemesフォルダーにテーマファイルを配置してください。\n\nフォルダー名は小文字のthemesにして、必要に応じてSDカードの状態を確認してください。\n\nthemezer.netでテーマを探せます。"},
      {"Error page out of bounds", "ページ番号が範囲外です"},
      {"(A): Install    (Y): Multiselect    (L)/(R): Previous/Next page", "A：適用　Y：複数選択　L/R：前後のページ"},
      {"(A): Open folder    (L)/(R): Previous/Next page", "A：フォルダーを開く　L/R：前後のページ"},
      {"(A): Install    (X): Options    (Y): Multiselect    (L)/(R): Previous/Next page", "A：適用　X：オプション　Y：複数選択　L/R：ページ移動"},
      {"(A): Add/Remove to selection    (Y): Clear selection   (+): Install selected", "A：選択切替　Y：選択解除　＋：選択分を適用"},
      {"Installing a theme failed, the process was cancelled", "テーマの適用に失敗したため、処理を中止しました。"},
      {"This theme has no wallpaper image", "このテーマには壁紙画像がありません。"},
      {"Download from the internet", "インターネットからダウンロード"},
      {"Select a provider from the list to download themes.\nYou can add custom providers as explained in the wiki on Github.", "一覧から配布サイトを選択してください。\n配布サイトの追加方法はGitHub Wikiを参照してください。"},
      {"Random themes", "ランダムなテーマ"},
      {"New themes", "新着テーマ"},
      {"Or search a theme by ID", "テーマIDで検索"},
      {"Search###SearchBtn", "検索###SearchBtn"},
      {"IDs are not names, searching a theme by name won't work, open your provider in the browser, select a theme and it should show its unique ID.", "IDはテーマ名ではありません。配布サイトでテーマを選択し、固有のIDを確認してください。"},
      {"Remote install from NxThemeTool", "NxThemeToolからリモート適用"},
      {"This feature is not available while running in applet mode, launch with title takeover.", "アプレットモードでは使用できません。タイトルオーバーライドで起動してください。"},
      {"Press A to install, B to cancel", "A：インストール　B：キャンセル"},
      {"You can install a theme directly from your pc with NxThemeTool, use the install command line option.", "NxThemeToolのinstallオプションでPCから直接テーマを適用できます。"},
      {"Keep the menu focus on this page or requests won't be executed", "リクエスト処理中はこの画面を開いたままにしてください。"},
      {"There was an error, try again.\n", "エラーが発生しました。もう一度お試しください。\n"},
      {"Cancel", "キャンセル"},
      {"Continue", "続行"},
      {"Yes", "はい"},
      {"No", "いいえ"},
      {"OK", "OK"},
      {"Back", "戻る"},
      {"Install", "インストール"},
      {"Install theme", "テーマを適用"},
      {"Preview", "プレビュー"},
      {"Options", "オプション"},
      {"Remove", "削除"},
      {"Done", "完了"},
      {"Restart", "再起動"},
      {"More options", "その他の設定"},
      {"Select", "選択"},
      {"Unselect", "選択解除"},
      {"Next", "次へ"},
      {"Previous", "前へ"},
      {"Themes folder", "テーマフォルダー"},
      {"Home menu", "HOME画面"},
      {"Home menu layout", "HOME画面レイアウト"},
      {"Lock screen", "ロック画面"},
      {"All applications", "すべてのアプリ"},
      {"System settings", "本体設定"},
      {"User page", "ユーザーページ"},
      {"Error", "エラー"},
      {"Warning", "警告"},
      {"Success", "成功"},
      {"Failed", "失敗"},
      {"Theme installed", "テーマを適用しました"},
      {"Theme removed", "テーマを削除しました"},
      {"Exit", "終了"},
      {"Close", "閉じる"},
      {"Page", "ページ"},
      {"Refresh", "更新"},
      {"Scan", "再スキャン"},
      {"Extract", "抽出"},
      {"Apply", "適用"},
      {"Title takeover", "タイトルオーバーライド"},
      {"Remote install", "リモートインストール"},
      {"About", "このアプリについて"},
      {"This theme is not compatible", "このテーマは互換性がありません"},
      {"Theme not supported", "このテーマは非対応です"},
      {"Font", "フォント"},
      {"Custom fonts", "カスタムフォント"},
      {"Installed themes", "適用済みテーマ"},
      {"This file is not supported", "このファイル形式には対応していません"},
      {"Please reboot your console", "本体を再起動してください"}
        };
        return translations;
    }
    inline const std::string& ConfigDirectory() {
#ifdef __SWITCH__
        static const std::string path = "sdmc:/config/NXThemesInstaller";
#else
        static const std::string path = "config/NXThemesInstaller";
#endif
        return path;
    }
    inline std::string ConfigPath() { return ConfigDirectory() + "/language.txt"; }
    inline std::string UserTranslationsPath() { return ConfigDirectory() + "/ja.tsv"; }
    inline void Init() {
        std::ifstream file(ConfigPath(), std::ios::binary);
        std::string value;
        if (std::getline(file, value))
            current = value == "ja" ? Language::Japanese : Language::English;
        // Optional editable translation file: English<TAB>Japanese, one entry per line.
        std::ifstream overrides(UserTranslationsPath(), std::ios::binary);
        std::string line;
        while (std::getline(overrides, line)) {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            if (line.empty() || line.front() == '#') continue;
            auto tab = line.find('\t');
            if (tab != std::string::npos && tab > 0) {
                std::string en = line.substr(0, tab);
                std::string ja = line.substr(tab + 1);
                auto replace_escapes = [](std::string& s) {
                    size_t pos = 0;
                    while ((pos = s.find("\\n", pos)) != std::string::npos) { s.replace(pos, 2, "\n"); ++pos; }
                };
                replace_escapes(en);
                replace_escapes(ja);
                Dictionary()[en] = ja;
            }
        }
    }
    inline void Set(Language language) {
        current = language;
        std::error_code ec;
        std::filesystem::create_directories(ConfigDirectory(), ec);
        std::ofstream file(ConfigPath(), std::ios::binary | std::ios::trunc);
        if (file.is_open()) file << (language == Language::Japanese ? "ja\n" : "en\n");
    }
    inline Language Get() { return current; }
    inline bool IsJapanese() { return current == Language::Japanese && japanFontAvailable; }
    inline const char* T(const char* english) {
        if (!english || !IsJapanese()) return english;
        const auto& dict = Dictionary();
        auto item = dict.find(english);
        return item != dict.end() ? item->second.c_str() : english;
    }
    inline const char* T(const std::string& english) { return T(english.c_str()); }
}
