
#pragma once

#ifndef __wcl_tabcontrol_hpp__
#define __wcl_tabcontrol_hpp__

#include <Commctrl.h>
#include <string>
#include "Window.hpp"

namespace wcl {

    struct TabControlItem : public TCITEM {
        static TabControlItem Text(const std::wstring &text);
    };

    class TabControl : public Window {
    public:
        TabControl();

    public:
        int InsertItem(const int index, const TabControlItem &item);

        int AdjustRect(BOOL bLarger, Rect *rect) const;

        int DeleteAllItems();

        int DeleteItem(const int index);

        int DeselectAll(BOOL allButThis);

        int GetCurFocus() const;

        int GetCurSel() const;

        int GetExtendedStyle() const;

        int GetImageList() const;

        int GetItem(const int index, TabControlItem *item) const;

        int GetItemCount() const;

        int GetItemRect(const int index, Rect *rect) const;

        int GetRowCount() const;

        int GetToolTips() const;

        int GetUnicodeFormat() const;

        int HighlightItem(const int index, BOOL hightlight);

        int HitTest(TCHITTESTINFO *info) const;

        int RemoveImage(const int index);

        int SetCurFocus(const int index);

        int SetCurSel(const int index);

        int SetImageList(const int imageListHandle);

        int SetItem(const int index, const TabControlItem &item);

        int SetToolTips(const int tooltipHandle);
    };

    inline TabControlItem TabControlItem::Text(const std::wstring &text) {
        TabControlItem item = {};

        item.pszText = const_cast<LPWSTR>(text.c_str());
        item.mask = TCIF_TEXT;

        return item;
    }

    inline TabControl::TabControl() : Window(WC_TABCONTROL) {}

    inline int TabControl::InsertItem(const int index, const TabControlItem &item) {
        return this->SendMessage_(TCM_INSERTITEM, index, &item);
    }

    inline int TabControl::AdjustRect(BOOL bLarger, Rect *rect) const {
        return this->SendMessage_(TCM_ADJUSTRECT, bLarger, rect);
    }

    inline int TabControl::DeleteAllItems() {
        return this->SendMessage_(TCM_DELETEALLITEMS);
    }

    inline int TabControl::DeleteItem(const int index) {
        return this->SendMessage_(TCM_DELETEITEM, index);
    }

    inline int TabControl::DeselectAll(BOOL allButThis) {
        return this->SendMessage_(TCM_DESELECTALL, allButThis);
    }

    inline int TabControl::GetCurFocus() const {
        return this->SendMessage_(TCM_GETCURFOCUS);
    }

    inline int TabControl::GetCurSel() const {
        return this->SendMessage_(TCM_GETCURSEL);
    }

    inline int TabControl::GetExtendedStyle() const {
        return this->SendMessage_(TCM_GETEXTENDEDSTYLE);
    }

    inline int TabControl::GetImageList() const {
        return this->SendMessage_(TCM_GETIMAGELIST);
    }

    inline int TabControl::GetItem(const int index, TabControlItem *item) const {
        return this->SendMessage_(TCM_GETITEM, index, item);
    }

    inline int TabControl::GetItemCount() const {
        return this->SendMessage_(TCM_GETITEMCOUNT);
    }

    inline int TabControl::GetItemRect(const int index, Rect *rect) const {
        return this->SendMessage_(TCM_GETITEMRECT, index, rect);
    }

    inline int TabControl::GetRowCount() const {
        return this->SendMessage_(TCM_GETROWCOUNT);
    }

    inline int TabControl::GetToolTips() const {
        return this->SendMessage_(TCM_GETTOOLTIPS);
    }

    inline int TabControl::GetUnicodeFormat() const {
        return this->SendMessage_(TCM_GETUNICODEFORMAT);
    }

    inline int TabControl::HighlightItem(const int index, BOOL hightlight) {
        return this->SendMessage_(TCM_HIGHLIGHTITEM, index, MAKEWPARAM(hightlight, 0));
    }

    inline int TabControl::HitTest(TCHITTESTINFO *info) const {
        return this->SendMessage_(TCM_HITTEST, NULL, info);
    }

    inline int TabControl::RemoveImage(const int index) {
        return this->SendMessage_(TCM_REMOVEIMAGE, index);
    }

    inline int TabControl::SetCurFocus(const int index) {
        return this->SendMessage_(TCM_SETCURFOCUS, index);
    }

    inline int TabControl::SetCurSel(const int index) {
        return this->SendMessage_(TCM_SETCURSEL, index);
    }

    inline int TabControl::SetImageList(const int imageListHandle) {
        return this->SendMessage_(TCM_SETIMAGELIST, 0L, imageListHandle);
    }

    inline int TabControl::SetItem(const int index, const TabControlItem &item) {
        return this->SendMessage_(TCM_SETITEM, index, &item);
    }

    inline int TabControl::SetToolTips(const int tooltipHandle) {
        return this->SendMessage_(TCM_SETTOOLTIPS, tooltipHandle);
    }
}

#endif 
