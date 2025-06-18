#pragma once

struct FSBMenuEntry
{
    FName Name;
    FText Label;
    FText Tooltip;
    TFunction<void()> Callback;
};