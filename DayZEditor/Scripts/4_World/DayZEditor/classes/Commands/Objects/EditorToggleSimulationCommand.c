class EditorToggleSimulationCommand: EditorCommand
{
	protected override bool Execute(Class sender, CommandArgs args)
	{
		super.Execute(sender, args);
		if (m_Editor.IsPlacing()) {
			return false;
		}
		
		// if we are controlling the player
		if (m_Editor.GetCurrentControl() && m_Editor.GetCurrentControl().IsInherited(PlayerBase)) {
			EditorObject player_object = m_Editor.GetEditorObject(m_Editor.GetCurrentControl());
			if (player_object) {
				player_object.Simulate = !player_object.Simulate;
				player_object.PropertyChanged("Simulate");
			}
		}
		
		EditorObjectMap selected_objects = m_Editor.GetSelectedObjects();
		if (selected_objects.Count() == 0) {
			return false;
		}
		
		foreach (int id, EditorObject editor_object: selected_objects) {
			editor_object.Simulate = !editor_object.Simulate;
			editor_object.PropertyChanged("Simulate");
		}
		
		return true;
	}
	
	override string GetName() 
	{
		return "Toggle Simulation";
	}
}