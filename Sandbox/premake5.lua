project "Sandbox"
    language "C++"
    kind "ConsoleApp"
    targetdir "%{wks.location}/build/bin"
	objdir "%{wks.location}/build/bin-int/%{prj.name}"
	
    includedirs {
		"%{prj.location}/src",
		"%{wks.location}/Haxxor/src",
		"%{wks.location}/Haxxor/src/Haxxor",
		"%{wks.location}/Haxxor/vendors/glm"
	}

	links {
		"Haxxor",
		"glfw",
		"glad",
	}

	files {
		"%{prj.location}/src/**.cpp",
		"%{prj.location}/src/**.h",
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