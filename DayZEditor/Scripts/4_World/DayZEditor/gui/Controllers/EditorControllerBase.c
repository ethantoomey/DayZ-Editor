class EditorControllerBase: ViewController
{
	protected Editor m_Editor;
	
	void EditorControllerBase()
	{
		m_Editor = GetEditor();
	}
	
	override void OnWidgetScriptInit(notnull Widget w)
	{
		m_Editor = GetEditor();
		super.OnWidgetScriptInit(w);
	}
}