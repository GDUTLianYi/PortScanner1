
PortScannerps.dll: dlldata.obj PortScanner_p.obj PortScanner_i.obj
	link /dll /out:PortScannerps.dll /def:PortScannerps.def /entry:DllMain dlldata.obj PortScanner_p.obj PortScanner_i.obj \
		kernel32.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
.c.obj:
	cl /c /Ox /DREGISTER_PROXY_DLL \
		$<

clean:
	@del PortScannerps.dll
	@del PortScannerps.lib
	@del PortScannerps.exp
	@del dlldata.obj
	@del PortScanner_p.obj
	@del PortScanner_i.obj
