// modded class EditorHudController
// {
// 	override void DoMultiSelect(int index_0, int index_1, ObservableCollection<EditorListItem> list)
// 	{
// 		int bottom, top;
// 		bottom = Math.Min(index_0, index_1);
// 		top = Math.Max(index_0, index_1);

// 		if (list.Count() < top) {
// 			EditorLog.Error("Could not multi select, top was out of range of list array");
// 			return;
// 		}

// 		for (int i = bottom; i < top; i++) {
// 			// if this element is filtered out
// 			if (!list[i].FilterType(PlacedSearchBarData)) {
// 				continue;
// 			}

// 			EditorPlacedListItem placed_list_item;
// 			// this is bad and wont work.. well it will but i dont like it
// 			if (Class.CastTo(placed_list_item, list[i])) {
// 				GetEditor().SelectObject(placed_list_item.GetEditorObject());
// 			}

// 			EditorDeletedListItem deleted_list_item;
// 			if (Class.CastTo(deleted_list_item, list[i])) {
// 				GetEditor().SelectHiddenObject(deleted_list_item.GetDeletedObject());
// 			}
// 		}
// 	}
// }