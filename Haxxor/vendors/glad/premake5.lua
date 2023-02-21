project "glad"
	kind "StaticLib"
	language "C"
	staticruntime "off"

	targetdir "%{wks.location}/build/bin"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"

	includedirs {
		"%{prj.location}/include",
		"%{prj.location}/include/glad",
	}

	files {
		"%{prj.location}/src/**.c",
	}

	filter "system:linux"
		pic "On"

		systemversion "latest"

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
        symbols "off"